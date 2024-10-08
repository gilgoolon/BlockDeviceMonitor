#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "udev_event.hpp"
#include "common/socket.hpp"
#include "common/utils.hpp"
#include "block_device.hpp"
#include "common/server_socket.hpp"
#include "proto/event.pb.h"

constexpr size_t NETLINK_BROADCAST = 1;
constexpr uint32_t PORT = 8080;

std::unique_ptr<Socket> make_netlink_uevent_socket()
{
    auto auto_sock = std::make_unique<Socket>(os::covered_call(::socket, AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT));

    struct sockaddr_nl sa;
    memset(&sa, 0, sizeof(sa));
    sa.nl_family = AF_NETLINK;
    sa.nl_pid = getpid();
    sa.nl_groups = NETLINK_BROADCAST;
    os::covered_call(::bind, auto_sock->get_socket_fd(), reinterpret_cast<sockaddr *>(&sa), sizeof(sa));

    return std::move(auto_sock);
}

std::unique_ptr<Socket> accept_client()
{
    ServerSocket server_socket(PORT);
    server_socket.listen(1);
    return std::move(server_socket.accept());
}

Event make_event(const BlockDevice &block_device, const UDevEvent &udev_event)
{
    Event event;
    event.set_action(udev_event.get_action());
    event.set_devname(udev_event.get_devname());
    event.set_vendor(block_device.retrieve_vendor());
    event.set_model(block_device.retrieve_model());
    event.set_size(block_device.retrieve_size());
    event.set_partitions(block_device.retrieve_partitions_count());
    event.set_type(block_device.retrieve_is_external() ? "external" : "internal");
    return event;
}

bool should_display_event(const UDevEvent &event)
{
    return event.is_block_device_event() && (event.get_action() == "add" || event.get_action() == "remove");
}

void display_event(const UDevEvent &event, const Socket &client_socket)
{
    const BlockDevice block_device(event.get_devname());
    std::string serialized;
    make_event(block_device, event).SerializeToString(&serialized);
    client_socket.send(serialized);
}

int main()
{
    auto netlink_socket = make_netlink_uevent_socket();

    std::cout << "Waiting for client connection..." << std::endl;
    auto client_socket = accept_client();
    std::cout << "Monitoring device events..." << std::endl;

    while (true)
    {
        auto buffer = netlink_socket->receive();
        const UDevEvent event(std::string(reinterpret_cast<char *>(buffer.data()), buffer.size()));
        if (!should_display_event(event))
        {
            continue;
        }
        display_event(event, *client_socket);
    }
    return EXIT_SUCCESS;
}
