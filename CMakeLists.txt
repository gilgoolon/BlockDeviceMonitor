cmake_minimum_required(VERSION 3.5.0)
project(BlockDeviceMonitor VERSION 0.1.0 LANGUAGES C CXX)
set(BUILD_SHARED_LIBS OFF)

find_package(Protobuf REQUIRED)
find_library(BLKID_LIB blkid REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp src/proto/*.pb.cc)
file(GLOB_RECURSE HEADERS src/*.hpp src/proto/*.pb.h)

add_executable(BlockDeviceMonitor ${SOURCES} ${HEADERS})
set_property(TARGET BlockDeviceMonitor PROPERTY CXX_STANDARD 20)
target_include_directories(BlockDeviceMonitor PRIVATE ${Protobuf_INCLUDE_DIRS})
target_link_libraries(BlockDeviceMonitor ${Protobuf_LIBRARIES})
target_include_directories(BlockDeviceMonitor PRIVATE ${BLKID_INCLUDE_DIRS})
target_link_libraries(BlockDeviceMonitor ${BLKID_LIB})