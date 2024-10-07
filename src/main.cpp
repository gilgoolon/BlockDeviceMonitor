#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>

#include "udevevent.hpp"
#include "common/socket.hpp"
#include "common/utils.hpp"
#include "block_device.hpp"
#include <fcntl.h>

constexpr size_t NETLINK_BROADCAST = 1;

std::unique_ptr<Socket> make_netlink_uevent_socket()
{
    auto auto_sock = std::make_unique<Socket>(os::covered_call(UNIX_INT_ERROR_VALUE, ::socket, AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT));

    struct sockaddr_nl sa;
    memset(&sa, 0, sizeof(sa));
    sa.nl_family = AF_NETLINK;
    sa.nl_pid = getpid();
    sa.nl_groups = NETLINK_BROADCAST;
    os::covered_call(UNIX_INT_ERROR_VALUE, ::bind, auto_sock->get_socket_fd(), reinterpret_cast<struct sockaddr *>(&sa), sizeof(sa));

    return std::move(auto_sock);
}

int main()
{
    const bool dev = true;
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
        std::cout << "Event received:" << std::endl
                  << "\tAction: " << event.get_action() << std::endl
                  << "\tDevname: " << event.get_devname() << std::endl
                  << "\tVendor: " << block_device.get_vendor() << std::endl
                  << "\tModel: " << block_device.get_model() << std::endl
                  << "\tSize: " << block_device.get_size() << std::endl
                  << "\tPartitions: " << block_device.get_partitions_count() << std::endl
                  << "\tType: " << (block_device.is_external() ? "external" : "internal") << std::endl;
    }
    return EXIT_SUCCESS;
}
