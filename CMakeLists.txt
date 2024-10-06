cmake_minimum_required(VERSION 3.5.0)
project(BlockDeviceMonitor VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.hpp)

add_executable(BlockDeviceMonitor ${SOURCES} ${HEADERS})

set_property(TARGET BlockDeviceMonitor PROPERTY CXX_STANDARD 20)
