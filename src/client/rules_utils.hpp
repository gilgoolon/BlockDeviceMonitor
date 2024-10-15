#pragma once
#include "../block_device/block_device.hpp"
#include "../proto/rule.pb.h"

namespace Rules {
bool is_rule_matching(const RuleFilter& rule, const BlockDevice& device);
};
