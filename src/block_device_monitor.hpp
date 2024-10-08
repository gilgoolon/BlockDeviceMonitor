#pragma once
#include <memory>

#include "writers/writer.hpp"
#include "readers/reader.hpp"
#include "udev_event.hpp"

class BlockDeviceMonitor final
{
public:
    explicit BlockDeviceMonitor(std::unique_ptr<IWriter> client_writer, std::unique_ptr<IReader> event_reader);

    void start();

private:
    std::unique_ptr<IWriter> _client_writer;
    std::unique_ptr<IReader> _event_reader;

    void report_event(const UDevEvent &event);

    bool should_report_event(const UDevEvent &event);
};

std::unique_ptr<BlockDeviceMonitor> make_block_device_monitor(uint32_t port);
