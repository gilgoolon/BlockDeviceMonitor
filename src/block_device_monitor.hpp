#pragma once
#include <memory>

#include "writers/writer.hpp"
#include "readers/reader.hpp"
#include "udev_event.hpp"
#include "client.hpp"
#include "client_handler.hpp"
#include "client_accepter.hpp"

static constexpr std::string_view ADD_ACTION_LABEL = "add";
static constexpr std::string_view REMOVE_ACTION_LABEL = "remove";

class BlockDeviceMonitor final
{
public:
    explicit BlockDeviceMonitor(std::unique_ptr<IReader> event_reader, std::unique_ptr<ClientAccepter> client_accepter);

    [[noreturn]] void start();

private:
    std::unique_ptr<IReader> _event_reader;
    std::unique_ptr<ClientAccepter> _client_accepter;
    std::vector<std::shared_ptr<Client>> _clients;
    std::shared_ptr<std::mutex> _clients_lock;
    std::shared_ptr<std::vector<Rule>> _rules;

    [[noreturn]] void accept_clients_loop();

    void handle_client(std::shared_ptr<Client> client);

    void report_event(const UDevEvent &event);

    bool should_report_event(const UDevEvent &event);
};

std::unique_ptr<BlockDeviceMonitor> make_block_device_monitor(uint32_t port);
