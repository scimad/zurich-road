project (cv2-imgproc)
cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(flip flip.cpp)
target_link_libraries( flip ${OpenCV_LIBS})

add_executable(rotate rotate.cpp)
target_link_libraries( rotate ${OpenCV_LIBS})
