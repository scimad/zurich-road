cmake_minimum_required(VERSION 3.1.0)

project(Graph-Plotter)


# CMAKE_POLICY(SET CMP0071 NEW)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOUIC ON)


set(CMAKE_PREFIX_PATH /home/scimad/Qt5.7.1/5.7/gcc_64/lib/cmake/Qt5)
if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets Quick REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

qt5_add_resources(QT_RESOURCES res/customgeometry.qrc)

add_executable(plotter
    include/beziercurve.hpp
    src/beziercurve.cpp
    src/main.cpp
    ${QT_RESOURCES}
)

target_link_libraries(plotter
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
)