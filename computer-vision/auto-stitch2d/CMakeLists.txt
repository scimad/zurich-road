project (auto-stitch2d)
cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(stitch stitch.cpp)
target_link_libraries( stitch ${OpenCV_LIBS})
