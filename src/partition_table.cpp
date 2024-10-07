#include <sstream>
#include <string>

#include "partition_table.hpp"
#include "common/utils.hpp"

std::vector<PartitionTableEntry> get_partition_table()
{
    const auto partition_table_data = os::read_text_file(PARTITION_TABLE_PATH);
    return parse_partition_table(partition_table_data);
}

std::vector<PartitionTableEntry> parse_partition_table(const std::string &partition_table)
{
    std::vector<PartitionTableEntry> entries;
    std::istringstream partition_table_stream(partition_table);
    std::string line;

    std::getline(partition_table_stream, line); // Header: major minor  #blocks  name
    std::getline(partition_table_stream, line); // An empty line

    while (std::getline(partition_table_stream, line))
    {
        std::istringstream iss(line);
        PartitionTableEntry entry;

        if (iss >> entry.major >> entry.minor >> entry.blocks >> entry.name)
        {
            entries.push_back(entry);
        }
    }

    return entries;
}
