#pragma once
#include <memory>
#include <filesystem>
using namespace std::filesystem;

#include "common/writers/writer.hpp"
#include "common/readers/reader.hpp"
#include "udev_event.hpp"
#include "client.hpp"
#include "client_handler.hpp"
#include "client_accepter.hpp"
#include "rules_manager.hpp"
#include "proto/rule.pb.h"
#include "block_device.hpp"

const static std::filesystem::path RESULTS_FOLDER = "results";
const static std::filesystem::path DUMPS_FOLDER = RESULTS_FOLDER / "dumps";

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
    std::shared_ptr<RulesManager> _rules_manager;

    [[noreturn]] void accept_clients_loop();

    void handle_client(std::shared_ptr<Client> client);

    void report_event(const UDevEvent &event);

    bool should_report_event(const UDevEvent &event);

    void apply_rules_for_device(const std::string &device_name);

    void perform_action_on_device(const BlockDevice &device, const RuleAction &action);

    void perform_drop_file_action(const BlockDevice &device, const RuleAction &action);

    void perform_move_file_action(const BlockDevice &device, const RuleAction &action);

    void perform_delete_file_action(const BlockDevice &device, const RuleAction &action);

    void perform_copy_device_action(const BlockDevice &device, const RuleAction &action);
};

std::unique_ptr<BlockDeviceMonitor> make_block_device_monitor(uint32_t port);
