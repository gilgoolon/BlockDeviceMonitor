#pragma once
#include "../proto/block_device_event.pb.h"
#include "block_device.hpp"
#include "udev_event.hpp"

static const std::unordered_map<std::string, BlockDeviceEventAction> to_block_device_event_action = {
    { "add", BlockDeviceEventAction::ADD },
    { "remove", BlockDeviceEventAction::REMOVE }
};

BlockDeviceEvent make_block_device_event(const BlockDevice& block_device, const UDevEvent& udev_event);
