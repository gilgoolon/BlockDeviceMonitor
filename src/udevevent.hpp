#include <string>
#include <map>

static constexpr std::string_view ATTRIBUTE_NAME_ACTION = "ACTION";
static constexpr std::string_view ATTRIBUTE_NAME_DEVNAME = "DEVNAME";
static constexpr std::string_view ATTRIBUTE_NAME_SUBSYSTEM = "SUBSYSTEM";

class UDevEvent
{
public:
    UDevEvent(const std::string_view &event);

    std::string get_attribute(const std::string &name);

    std::string get_action();

    std::string get_devname();

    std::string get_subsystem();

private:
    std::string _description;
    std::map<std::string, std::string> _attributes;
};
