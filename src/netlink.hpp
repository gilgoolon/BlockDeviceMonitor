#include <memory>
#include "common/network/socket.hpp"

namespace netlink
{
    std::shared_ptr<Socket> make_netlink_uevent_socket();
};
