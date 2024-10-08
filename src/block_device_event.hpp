#include "block_device.hpp"
#include "udev_event.hpp"
#include "proto/block_device_event.pb.h"

BlockDeviceEvent make_block_device_event(const BlockDevice &block_device, const UDevEvent &udev_event)
{
    BlockDeviceEvent event;
    event.set_action(udev_event.get_action());
    event.set_devname(udev_event.get_devname());
    event.set_vendor(block_device.retrieve_vendor());
    event.set_model(block_device.retrieve_model());
    event.set_size(block_device.retrieve_size());
    event.set_partitions(block_device.retrieve_partitions_count());
    event.set_type(block_device.retrieve_is_external() ? "external" : "internal");
    return event;
}

bool should_display_event(const UDevEvent &event)
{
    return event.is_block_device_event() && (event.get_action() == "add" || event.get_action() == "remove");
}
