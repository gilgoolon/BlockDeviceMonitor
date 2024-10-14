#include <regex>

#include "rules_utils.hpp"

bool rules::is_rule_matching(const RuleFilter &rule, const BlockDevice &device)
{
    if (rule.has_model_regex() && !std::regex_match(device.retrieve_model(), std::regex(rule.model_regex())))
        return false;
    if (rule.has_vendor_regex() && !std::regex_match(device.retrieve_vendor(), std::regex(rule.vendor_regex())))
        return false;
    return true;
}