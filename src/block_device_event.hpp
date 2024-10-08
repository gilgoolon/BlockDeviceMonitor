#pragma once
#include "block_device.hpp"
#include "udev_event.hpp"
#include "proto/block_device_event.pb.h"

BlockDeviceEvent make_block_device_event(const BlockDevice &block_device, const UDevEvent &udev_event);
