#include <memory>
#include "common/socket.hpp"

namespace netlink
{
    std::unique_ptr<Socket> make_netlink_uevent_socket();
};
