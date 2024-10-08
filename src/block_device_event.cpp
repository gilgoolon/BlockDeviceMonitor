#include "block_device_event.hpp"
#include "exceptions.hpp"

BlockDeviceEventAction to_block_device_event_action(const std::string &action)
{
    if (action == "add")
    {
        return BlockDeviceEventAction::ADD;
    }
    else if (action == "remove")
    {
        return BlockDeviceEventAction::REMOVE;
    }
    else
    {
        throw Exception(ExceptionCode::InvalidArgument, "Unmapped action value '" + action + "' in to_action(string)");
    }
}

BlockDeviceEvent make_block_device_event(const BlockDevice &block_device, const UDevEvent &udev_event)
{
    BlockDeviceEvent event;
    event.set_action(to_block_device_event_action(udev_event.get_action()));
    event.set_devname(udev_event.get_devname());
    event.set_vendor(block_device.retrieve_vendor());
    event.set_model(block_device.retrieve_model());
    event.set_size(block_device.retrieve_size());
    event.set_partitions(block_device.retrieve_partitions_count());
    event.set_type(block_device.retrieve_is_external() ? BlockDeviceType::EXTERNAL : BlockDeviceType::INTERNAL);
    return event;
}
