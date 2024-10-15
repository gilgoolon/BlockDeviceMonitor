#pragma once
#include <filesystem>
#include <memory>
using namespace std::filesystem;

#include "block_device/block_device.hpp"
#include "block_device/udev_event.hpp"
#include "client/client.hpp"
#include "client/client_accepter.hpp"
#include "client/client_handler.hpp"
#include "client/rules_manager.hpp"
#include "common/readers/reader.hpp"
#include "common/writers/writer.hpp"
#include "proto/rule.pb.h"

const static std::filesystem::path DUMPS_FOLDER = "dumps";
const static std::filesystem::path TEMP_MOUNT_TEMPLATE_PREFIX = "/tmp/block-device-monitor-mount-";

class BlockDeviceMonitor final {
public:
    explicit BlockDeviceMonitor(std::filesystem::path results_path, std::unique_ptr<IReader> event_reader, std::unique_ptr<ClientAccepter> client_accepter);

    [[noreturn]] void start();

private:
    std::filesystem::path _results_path;
    std::unique_ptr<IReader> _event_reader;
    std::unique_ptr<ClientAccepter> _client_accepter;
    std::vector<std::shared_ptr<Client>> _clients;
    std::shared_ptr<std::mutex> _clients_lock;
    std::shared_ptr<RulesManager> _rules_manager;

    [[noreturn]] void accept_clients_loop();

    void handle_client(std::shared_ptr<Client> client);

    void handle_event(const UDevEvent& event);

    void report_event(const UDevEvent& event);

    bool should_report_event(const UDevEvent& event);

    void apply_rules_for_device(const std::string& device_name);

    void perform_action_on_device(const BlockDevice& device, const RuleAction& action);

    void perform_drop_file_action(const BlockDevice& device, const RuleAction& action);

    void perform_move_file_action(const BlockDevice& device, const RuleAction& action);

    void perform_delete_file_action(const BlockDevice& device, const RuleAction& action);

    void perform_copy_device_action(const BlockDevice& device, const RuleAction& action);

    void add_client(std::shared_ptr<Client> client);

    void remove_client(const std::shared_ptr<Client>& client);
};

std::unique_ptr<BlockDeviceMonitor> make_block_device_monitor(const std::filesystem::path& results_path, uint32_t port);
