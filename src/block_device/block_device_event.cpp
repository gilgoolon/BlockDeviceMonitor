#include "block_device_event.hpp"
#include "../exceptions.hpp"

BlockDeviceEventAction to_block_device_event_action(const std::string& action)
{
    if (action == "add") {
        return BlockDeviceEventAction::ADD;
    } else if (action == "remove") {
        return BlockDeviceEventAction::REMOVE;
    } else {
        throw Exception(ExceptionCode::InvalidArgument, "unmapped action value '" + action + "' in to_action(string)");
    }
}

BlockDeviceEvent make_block_device_event(const BlockDevice& block_device, const UDevEvent& udev_event)
{
    BlockDeviceEvent event;
    EMPTY_CATCH_BEG
    event.set_action(to_block_device_event_action(udev_event.get_action()));
    EMPTY_CATCH_END(ExceptionCode::MissingInformation)
    EMPTY_CATCH_BEG
    event.set_devname(udev_event.get_devname());
    EMPTY_CATCH_END(ExceptionCode::MissingInformation)
    EMPTY_CATCH_BEG
    event.set_vendor(block_device.retrieve_vendor());
    EMPTY_CATCH_END(ExceptionCode::MissingInformation)
    EMPTY_CATCH_BEG
    event.set_model(block_device.retrieve_model());
    EMPTY_CATCH_END(ExceptionCode::MissingInformation)
    EMPTY_CATCH_BEG
    event.set_size(block_device.retrieve_size());
    EMPTY_CATCH_END(ExceptionCode::MissingInformation)
    EMPTY_CATCH_BEG
    event.set_partitions(block_device.retrieve_partitions_count());
    EMPTY_CATCH_END(ExceptionCode::MissingInformation)
    EMPTY_CATCH_BEG
    event.set_type(block_device.retrieve_is_external() ? BlockDeviceType::EXTERNAL : BlockDeviceType::INTERNAL);
    EMPTY_CATCH_END(ExceptionCode::MissingInformation)
    return event;
}
