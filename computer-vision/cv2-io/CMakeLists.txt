project (cv2-io)
cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(read_write read_write.cpp)
target_link_libraries( read_write ${OpenCV_LIBS})

add_executable(inv_gray inverse_gray.cpp)
target_link_libraries( inv_gray ${OpenCV_LIBS})
