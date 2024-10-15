#include "rules_manager.hpp"
#include "../common/autos/auto_lock.hpp"

RulesManager::RulesManager()
    : _mutex(std::make_shared<std::mutex>())
{
}

void RulesManager::add_rule(const Rule &rule)
{
    Autos::AutoLock auto_lock(_mutex);
    _rules.push_back(rule);
}

void RulesManager::remove_rule(const uint32_t rule_index)
{
    Autos::AutoLock auto_lock(_mutex);
    _rules.erase(_rules.begin() + rule_index);
}

std::vector<Rule>::iterator RulesManager::begin()
{
    return _rules.begin();
}

std::vector<Rule>::iterator RulesManager::end()
{
    return _rules.end();
}

std::shared_ptr<std::mutex> RulesManager::get_lock()
{
    return _mutex;
}
