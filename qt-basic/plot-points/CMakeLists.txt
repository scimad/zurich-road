project (Graph-Plotter)

cmake_minimum_required(VERSION 3.1.0)

SET(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_compile_options(-fPIC)


SET(CMAKE_AUTOMOC ON)
# SET(CMAKE_AUTORCC ON)
# SET(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH /home/scimad/Qt5.7.1/5.7/gcc_64/lib/cmake/Qt5)
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(/home/scimad/Qt5.7.1/5.7/gcc_64/include)

add_executable(plotter
    include/qcustomplot.h
    src/qcustomplot.cpp
    src/main.cpp
)

target_link_libraries(plotter
    Qt5::Widgets
    Qt5::PrintSupport
)
