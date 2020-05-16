cmake_minimum_required(VERSION 3.1.0)

project(helloworld)

set(CMAKE_PREFIX_PATH /home/scimad/Qt5.7.1/5.7/gcc_64/lib/cmake/Qt5)
if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(helloworld
    src/main.cpp
)

target_link_libraries(helloworld Qt5::Widgets)