#include "block_device_monitor.hpp"
#include "block_device.hpp"
#include "block_device_event.hpp"
#include "netlink.hpp"
#include "writers/socket_writer.hpp"
#include "readers/socket_reader.hpp"

BlockDeviceMonitor::BlockDeviceMonitor(std::unique_ptr<IWriter> client_writer, std::unique_ptr<IReader> event_reader)
    : _client_writer(std::move(client_writer)), _event_reader(std::move(event_reader))
{
}

void BlockDeviceMonitor::start()
{
    while (true)
    {
        auto buffer = _event_reader->read();
        const UDevEvent event(to_string(buffer));
        if (!should_report_event(event))
        {
            continue;
        }
        report_event(event);
    }
}

void BlockDeviceMonitor::report_event(const UDevEvent &event)
{
    const BlockDevice block_device(event.get_devname());
    std::string serialized;
    make_block_device_event(block_device, event).SerializeToString(&serialized);
    _client_writer->write(to_buffer(serialized));
}

bool BlockDeviceMonitor::should_report_event(const UDevEvent &event)
{
    return event.is_block_device_event() && (event.get_action() == "add" || event.get_action() == "remove");
}

std::unique_ptr<BlockDeviceMonitor> make_block_device_monitor(const uint32_t port)
{
    auto netlink_socket = netlink::make_netlink_uevent_socket();
    std::cout << "Waiting for client connection on port " << std::to_string(port) << std::endl;
    auto client_socket = accept_client(port);
    std::cout << "Monitoring device events..." << std::endl;
    return std::make_unique<BlockDeviceMonitor>(
        std::make_unique<SocketWriter>(std::move(client_socket)),
        std::make_unique<SocketReader>(std::move(netlink_socket)));
}
