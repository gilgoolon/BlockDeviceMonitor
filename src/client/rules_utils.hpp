#include "../proto/rule.pb.h"
#include "../block_device/block_device.hpp"

namespace rules
{
    bool is_rule_matching(const RuleFilter &rule, const BlockDevice &device);
};
