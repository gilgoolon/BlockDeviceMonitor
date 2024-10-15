#pragma once
#include <memory>
#include "../common/network/socket.hpp"

namespace Netlink
{
    std::shared_ptr<Socket> make_netlink_uevent_socket();
};
