#pragma once
#include "../proto/block_device_event.pb.h"
#include "block_device.hpp"
#include "udev_event.hpp"

BlockDeviceEventAction to_block_device_event_action(const std::string& action);

BlockDeviceEvent make_block_device_event(const BlockDevice& block_device, const UDevEvent& udev_event);
