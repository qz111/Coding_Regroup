cmake_minimum_required(VERSION 3.1)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")


project(Regroup)

add_subdirectory(../../nlohmann/json
   ${CMAKE_CURRENT_BINARY_DIR}/nlohmann_json)

add_executable (testregroup src/testregroup.cpp src/Utility/ioProcess/iofromjson.cpp src/Utility/regroupProcess/processing.cpp src/Control/monitor.cpp)
target_link_libraries (testregroup nlohmann_json::nlohmann_json)







