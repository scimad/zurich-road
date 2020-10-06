project (Graph-Plotter)

cmake_minimum_required(VERSION 3.1.0)

# SET(CMAKE_POSITION_INDEPENDENT_CODE ON)
# add_compile_options(-fPIC)

#set(CMAKE_PREFIX_PATH /home/scimad/Qt5.7.1/5.7/gcc_64/lib/cmake/Qt5)
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_cpp(MOC include/mainwindow.h include/qcustomplot.h)
qt5_wrap_ui(UI src/mainwindow.ui)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(plotter
    ${MOC}
    ${UI}
    src/qcustomplot.cpp
    src/main.cpp
    src/mainwindow.cpp
)

target_link_libraries(plotter
    Qt5::Widgets
    Qt5::PrintSupport
)
