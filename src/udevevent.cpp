#include <stdexcept>
#include <iostream>

#include "udevevent.hpp"
#include "common/utils.hpp"

static constexpr size_t EXPECTED_TOKENS_EVENT_ATTRIBUTE = 2;
static constexpr std::string_view DEFAULT_ATTRIBUTE_VALUE = "unknown";

UDevEvent::UDevEvent(const std::string_view &event)
{
    size_t total_length = 0;
    bool is_first = true;
    for (std::string current = event.data() + total_length; current.length(); current = std::string(event.data() + total_length))
    {
        total_length += current.size() + 1;
        if (is_first)
        {
            is_first = false;
            _description = current;
            continue;
        }
        const auto tokens = strings::split(current, '=');
        if (tokens.size() != EXPECTED_TOKENS_EVENT_ATTRIBUTE)
        {
            throw std::invalid_argument("Expected " + std::to_string(EXPECTED_TOKENS_EVENT_ATTRIBUTE) + " tokens when splitting event line by '=' token. Line: '" + current + "'.");
        }
        const auto attribute_name = tokens.front();
        const auto attribute_value = tokens.back();
        _attributes.insert_or_assign(attribute_name, attribute_value);
    }
}

std::string UDevEvent::get_attribute(const std::string &name)
{
    if (_attributes.find(name) != _attributes.end())
    {
        return _attributes[name];
    }
    return std::string(DEFAULT_ATTRIBUTE_VALUE);
}

std::string UDevEvent::get_action()
{
    return get_attribute(std::string(ATTRIBUTE_NAME_ACTION));
}

std::string UDevEvent::get_devname()
{
    return get_attribute(std::string(ATTRIBUTE_NAME_DEVNAME));
}

std::string UDevEvent::get_subsystem()
{
    return get_attribute(std::string(ATTRIBUTE_NAME_SUBSYSTEM));
}
