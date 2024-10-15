#pragma once
#include <map>
#include <string>

class UDevEvent final {
public:
    explicit UDevEvent(const std::string& event);

    std::string get_attribute(const std::string& name) const;

    std::string get_action() const;

    std::string get_devname() const;

    std::string get_subsystem() const;

    bool is_block_device_event() const;

    bool is_add_event() const;

    bool is_remove_event() const;

private:
    std::string _description;
    std::map<std::string, std::string> _attributes;

    void parse_event(const std::string& event);
};
