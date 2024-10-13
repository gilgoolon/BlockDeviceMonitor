#include <thread>
#include <algorithm>

#include "block_device_monitor.hpp"
#include "block_device.hpp"
#include "block_device_event.hpp"
#include "netlink.hpp"
#include "writers/socket_writer.hpp"
#include "readers/socket_reader.hpp"
#include "common/auto_lock.hpp"

BlockDeviceMonitor::BlockDeviceMonitor(std::unique_ptr<IReader> event_reader, std::unique_ptr<ClientAccepter> client_accepter)
    : _event_reader(std::move(event_reader)), _client_accepter(std::move(client_accepter)), _clients_lock(std::make_shared<std::mutex>()), _rules(std::make_shared<std::vector<Rule>>())
{
}

void BlockDeviceMonitor::start()
{
    std::thread accept_clients_tread(&BlockDeviceMonitor::accept_clients_loop, this);
    accept_clients_tread.detach();

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

void BlockDeviceMonitor::accept_clients_loop()
{
    while (true)
    {
        auto client = _client_accepter->accept();
        std::thread handle_client_thread(&BlockDeviceMonitor::handle_client, this, std::move(client));
        handle_client_thread.detach();
    }
}

void BlockDeviceMonitor::handle_client(std::shared_ptr<Client> client)
{
    {
        AutoLock auto_clients_lock(_clients_lock);
        _clients.push_back(client);
    }
    ClientHandler handler(client, _rules);
    try
    {
        handler.handle_indefinitely();
    }
    catch (...)
    {
    }
    {
        AutoLock auto_clients_lock(_clients_lock);
        _clients.erase(std::remove(_clients.begin(), _clients.end(), client));
    }
}

void BlockDeviceMonitor::report_event(const UDevEvent &event)
{
    const BlockDevice block_device(event.get_devname());
    ReportEventServerMessageContent message_content;
    *message_content.mutable_event() = make_block_device_event(block_device, event);

    ServerMessage message;
    message.mutable_content()->PackFrom(message_content);
    for (auto &client : _clients)
    {
        client->send(message);
    }
}

bool BlockDeviceMonitor::should_report_event(const UDevEvent &event)
{
    return event.is_block_device_event() && (event.get_action() == ADD_ACTION_LABEL || event.get_action() == REMOVE_ACTION_LABEL);
}

std::unique_ptr<BlockDeviceMonitor> make_block_device_monitor(const uint32_t port)
{
    auto netlink_socket = netlink::make_netlink_uevent_socket();
    return std::make_unique<BlockDeviceMonitor>(
        std::make_unique<SocketReader>(std::move(netlink_socket)),
        std::make_unique<ClientAccepter>(std::make_unique<ServerSocket>(port)));
}
