#pragma once
#include <memory>
#include <mutex>
#include <vector>

#include "../proto/rule.pb.h"

class RulesManager final {
public:
    explicit RulesManager();

    void add_rule(const Rule& rule);

    void remove_rule(uint32_t rule_index);

    std::vector<Rule>::iterator begin();

    std::vector<Rule>::iterator end();

    std::shared_ptr<std::mutex> get_lock();

private:
    std::vector<Rule> _rules;
    std::shared_ptr<std::mutex> _mutex;
};