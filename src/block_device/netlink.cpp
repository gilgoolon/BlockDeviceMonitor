#include <linux/netlink.h>
#include <sys/socket.h>

#include "../common/os_utils.hpp"
#include "netlink.hpp"

std::shared_ptr<Socket> Netlink::make_netlink_uevent_socket()
{
    auto auto_sock = std::make_unique<Socket>(OS::covered_call(::socket, AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT));

    static constexpr uint32_t NETLINK_BROADCAST = 1;
    static constexpr uint32_t NETLINK_ADDRESS_FORMAT = AF_NETLINK;

    struct sockaddr_nl sa;
    std::memset(&sa, 0, sizeof(sa));
    sa.nl_family = NETLINK_ADDRESS_FORMAT;
    sa.nl_pid = getpid();
    sa.nl_groups = NETLINK_BROADCAST;
    OS::covered_call(::bind, auto_sock->get_socket_fd(), reinterpret_cast<sockaddr*>(&sa), sizeof(sa));

    return auto_sock;
}
