#pragma once
#include "../common/network/socket.hpp"
#include <memory>

namespace Netlink {
std::shared_ptr<Socket> make_netlink_uevent_socket();
};
