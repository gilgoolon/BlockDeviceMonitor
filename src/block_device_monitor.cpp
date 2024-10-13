#include <thread>
#include <algorithm>
#include <regex>

#include "block_device_monitor.hpp"
#include "block_device.hpp"
#include "block_device_event.hpp"
#include "netlink.hpp"
#include "writers/socket_writer.hpp"
#include "readers/socket_reader.hpp"
#include "common/auto_lock.hpp"
#include "common/utils.hpp"

BlockDeviceMonitor::BlockDeviceMonitor(std::unique_ptr<IReader> event_reader, std::unique_ptr<ClientAccepter> client_accepter)
    : _event_reader(std::move(event_reader)), _client_accepter(std::move(client_accepter)), _clients_lock(std::make_shared<std::mutex>()), _rules_manager(std::make_shared<RulesManager>())
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
        if (event.is_add_event())
        {
            apply_rules_for_device(event.get_devname());
        }
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
    ClientHandler handler(client, _rules_manager);
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
    return event.is_block_device_event() && (event.is_add_event() || event.is_remove_event());
}

void BlockDeviceMonitor::apply_rules_for_device(const std::string &device_name)
{
    const BlockDevice device(device_name);
    for (const auto &rule : *_rules_manager)
    {
        if (!rules::is_rule_matching(rule.filter(), device))
        {
            continue;
        }
        std::cout << "Matched rule for device: " << device_name << std::endl;
        perform_action_on_device(device, rule.action());
    }
}

void BlockDeviceMonitor::perform_action_on_device(const BlockDevice &device, const RuleAction &action)
{
    switch (action.type())
    {
    case DROP_FILE:
        perform_drop_file_action(device, action);
        break;

    case MOVE_FILE:
        perform_move_file_action(device, action);
        break;

    case DELETE_FILE:
        perform_delete_file_action(device, action);
        break;

    case COPY_DEVICE:
        perform_copy_device_action(device, action);
        break;

    default:
        throw Exception(ExceptionCode::InvalidArgument, "action.type was an invalid enum value on perform_action_on_device()");
    }
}

void BlockDeviceMonitor::perform_drop_file_action(const BlockDevice &device, const RuleAction &action)
{
    RuleActionDropFile drop_file_action;
    action.action().UnpackTo(&drop_file_action);
}

void BlockDeviceMonitor::perform_move_file_action(const BlockDevice &device, const RuleAction &action)
{
}

void BlockDeviceMonitor::perform_delete_file_action(const BlockDevice &device, const RuleAction &action)
{
}

void BlockDeviceMonitor::perform_copy_device_action(const BlockDevice &device, const RuleAction &action)
{
}

std::unique_ptr<BlockDeviceMonitor> make_block_device_monitor(const uint32_t port)
{
    auto netlink_socket = netlink::make_netlink_uevent_socket();
    return std::make_unique<BlockDeviceMonitor>(
        std::make_unique<SocketReader>(std::move(netlink_socket)),
        std::make_unique<ClientAccepter>(std::make_unique<ServerSocket>(port)));
}
