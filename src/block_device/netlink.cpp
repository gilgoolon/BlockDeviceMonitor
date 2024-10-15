#include <sys/socket.h>
#include <linux/netlink.h>

#include "netlink.hpp"
#include "../common/os_utils.hpp"

static constexpr size_t NETLINK_BROADCAST = 1;

std::shared_ptr<Socket> Netlink::make_netlink_uevent_socket()
{
    auto auto_sock = std::make_unique<Socket>(OS::covered_call(::socket, AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT));

    struct sockaddr_nl sa;
    memset(&sa, 0, sizeof(sa));
    sa.nl_family = AF_NETLINK;
    sa.nl_pid = getpid();
    sa.nl_groups = NETLINK_BROADCAST;
    OS::covered_call(::bind, auto_sock->get_socket_fd(), reinterpret_cast<sockaddr *>(&sa), sizeof(sa));

    return std::move(auto_sock);
}
