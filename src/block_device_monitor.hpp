#pragma once
#include <memory>

#include "writers/writer.hpp"

class BlockDeviceMonitor final
{
public:
    explicit BlockDeviceMonitor(std::unique_ptr<IWriter> writer);

private:
    std::unique_ptr<IWriter> _writer;
};
