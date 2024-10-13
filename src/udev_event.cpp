#include <stdexcept>
#include <iostream>

#include "udev_event.hpp"
#include "common/utils.hpp"

static constexpr char ATTRIBUTE_NAME_VALUE_SEPARATOR = '=';
static constexpr size_t EXPECTED_TOKENS_EVENT_ATTRIBUTE = 2;
static constexpr std::string_view DEFAULT_ATTRIBUTE_VALUE = "unknown";
static constexpr std::string_view ATTRIBUTE_NAME_ACTION = "ACTION";
static constexpr std::string_view ATTRIBUTE_NAME_DEVNAME = "DEVNAME";
static constexpr std::string_view ATTRIBUTE_NAME_SUBSYSTEM = "SUBSYSTEM";
static constexpr std::string_view SUBSYSTEM_BLOCK = "block";

UDevEvent::UDevEvent(const std::string &event)
{
    parse_event(event);
}

void UDevEvent::parse_event(const std::string &event)
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
        const auto tokens = strings::split(current, ATTRIBUTE_NAME_VALUE_SEPARATOR, 1); // only split by a single separator
        if (tokens.size() == 1)                                                         // no separators found
        {
            throw std::invalid_argument("Expected " + strings::to_string(ATTRIBUTE_NAME_VALUE_SEPARATOR) + " tokens when splitting event line by '=' token. Line: '" + current + "'.");
        }
        const auto attribute_name = tokens.front();
        const auto attribute_value = tokens.back();
        _attributes.insert_or_assign(attribute_name, attribute_value);
    }
}

std::string UDevEvent::get_attribute(const std::string &name) const
{
    if (_attributes.contains(name))
    {
        return _attributes.at(name);
    }
    return std::string(DEFAULT_ATTRIBUTE_VALUE);
}

bool UDevEvent::is_block_device_event() const
{
    return get_subsystem() == SUBSYSTEM_BLOCK;
}

bool UDevEvent::is_add_event() const
{
    return get_action() == ADD_ACTION_LABEL;
}

bool UDevEvent::is_remove_event() const
{
    return get_action() == REMOVE_ACTION_LABEL;
}

std::string UDevEvent::get_action() const
{
    return get_attribute(std::string(ATTRIBUTE_NAME_ACTION));
}

std::string UDevEvent::get_devname() const
{
    return get_attribute(std::string(ATTRIBUTE_NAME_DEVNAME));
}

std::string UDevEvent::get_subsystem() const
{
    return get_attribute(std::string(ATTRIBUTE_NAME_SUBSYSTEM));
}
