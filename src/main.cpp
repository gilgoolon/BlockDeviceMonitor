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

#include "udevevent.hpp"
#include "common/socket.hpp"
#include "common/utils.hpp"
#include "block_device.hpp"
#include "common/server_socket.hpp"
#include "proto/event.pb.h"

constexpr size_t NETLINK_BROADCAST = 1;
constexpr uint32_t PORT = 8080;

std::unique_ptr<Socket> make_netlink_uevent_socket()
{
    auto auto_sock = std::make_unique<Socket>(os::covered_call(UNIX_INT_ERROR_VALUE, ::socket, AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT));

    struct sockaddr_nl sa;
    memset(&sa, 0, sizeof(sa));
    sa.nl_family = AF_NETLINK;
    sa.nl_pid = getpid();
    sa.nl_groups = NETLINK_BROADCAST;
    os::covered_call(UNIX_INT_ERROR_VALUE, ::bind, auto_sock->get_socket_fd(), reinterpret_cast<sockaddr *>(&sa), sizeof(sa));

    return std::move(auto_sock);
}

std::unique_ptr<Socket> accept_client()
{
    ServerSocket server_socket(PORT);
    server_socket.listen(1);
    return std::move(server_socket.accept());
}

int main()
{
    const bool dev = false;

    std::cout << "Waiting for client connection..." << std::endl;
    auto client_socket = accept_client();

    auto netlink_socket = make_netlink_uevent_socket();
    std::cout << "Monitoring device events..." << std::endl;

    while (true)
    {
        auto buffer = netlink_socket->receive();
        const std::string event_data(reinterpret_cast<char *>(buffer.data()), buffer.size());
        const UDevEvent event(event_data);
        if (!event.is_block_device_event() || (!dev && event.get_action() != "add" && event.get_action() != "remove"))
        {
            continue;
        }
        const BlockDevice block_device(event.get_devname());
        Event event_to_send;
        event_to_send.set_action(event.get_action());
        event_to_send.set_devname(event.get_devname());
        event_to_send.set_vendor(block_device.get_vendor());
        event_to_send.set_model(block_device.get_model());
        event_to_send.set_size(block_device.get_size());
        event_to_send.set_partitions(block_device.get_partitions_count());
        event_to_send.set_type(block_device.is_external() ? "external" : "internal");
        std::string serialized;
        event_to_send.SerializeToString(&serialized);
        client_socket->send(serialized);
    }
    return EXIT_SUCCESS;
}
