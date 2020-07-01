project (cv2-gradient)
cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(gradient gradient.cpp)
target_link_libraries( gradient ${OpenCV_LIBS})
