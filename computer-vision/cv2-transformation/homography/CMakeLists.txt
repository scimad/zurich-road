project (cv2-transformation)
cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(homography homography.cpp)
target_link_libraries( homography ${OpenCV_LIBS})
