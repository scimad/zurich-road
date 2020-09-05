project (primitive-transformation)
cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(affine affine.cpp)
target_link_libraries( affine ${OpenCV_LIBS})
