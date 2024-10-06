#include <string>
#include <map>

class UDevEvent final
{
public:
    UDevEvent(const std::string_view &event);

    std::string get_attribute(const std::string &name) const;

    std::string get_action() const;

    std::string get_devname() const;

    std::string get_subsystem() const;

    bool is_block_device_event() const;

private:
    std::string _description;
    std::map<std::string, std::string> _attributes;
};
