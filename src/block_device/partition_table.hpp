#pragma once
#include <string>
#include <vector>

constexpr std::string_view PARTITION_TABLE_PATH = "/proc/partitions";

struct PartitionTableEntry
{
    size_t major;
    size_t minor;
    size_t blocks;
    std::string name;
};

std::vector<PartitionTableEntry> get_partition_table();

std::vector<PartitionTableEntry> parse_partition_table(const std::string &partition_table);
