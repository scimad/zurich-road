project (test-nn)
cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_SOURCE_DIR}/lib/MyNN/include)
link_directories(${CMAKE_SOURCE_DIR}/lib/MyNN/build)

add_executable(test main.cpp)

target_link_libraries(test mynn)