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

#define UEVENT_BUFFER_SIZE 2048

std::unique_ptr<Socket> make_netlink_uevent_socket()
{
    auto auto_sock = std::make_unique<Socket>(os::covered_call(UNIX_INT_ERROR_VALUE, ::socket, AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT));
    struct sockaddr_nl sa;
    memset(&sa, 0, sizeof(sa));
    sa.nl_family = AF_NETLINK;
    sa.nl_pid = getpid();
    sa.nl_groups = 1; // Receive broadcast messages from the kernel
    os::covered_call(UNIX_INT_ERROR_VALUE, ::bind, auto_sock->get_socket_fd(), reinterpret_cast<struct sockaddr *>(&sa), sizeof(sa));

    return std::move(auto_sock);
}

int main()
{
    auto netlink_socket = make_netlink_uevent_socket();
    std::cout << "Monitoring device events..." << std::endl;

    while (true)
    {
        auto buffer = netlink_socket->receive();
        std::cout << "Event received:" << std::endl;
        const std::string event_data(reinterpret_cast<char *>(buffer.data()), buffer.size());
        UDevEvent event(event_data);
        std::cout << "\tAction: " << event.get_action() << std::endl
                  << "\tDevname: " << event.get_devname() << std::endl
                  << "\tSubsystem: " << event.get_subsystem() << std::endl;
    }
    return EXIT_SUCCESS;
}
