#include <iostream>

#include "block_device_event.hpp"
#include "netlink.hpp"

static constexpr uint32_t PORT = 8080;

void display_event(const UDevEvent &event, const Socket &client_socket)
{
    const BlockDevice block_device(event.get_devname());
    std::string serialized;
    make_block_device_event(block_device, event).SerializeToString(&serialized);
    client_socket.send(serialized);
}

int main()
{
    auto netlink_socket = netlink::make_netlink_uevent_socket();
    std::cout << "Waiting for client connection..." << std::endl;
    auto client_socket = accept_client(PORT);
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
