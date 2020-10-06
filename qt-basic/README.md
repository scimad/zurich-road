# Basic Qt with cmake

## ... and miles to go before I sleep.

This folder contains basics of Qt with cmake.

Things to remember while working with Qt (Tested with cmake version 3.16.3, Qt5.7, Ubuntu 20.04):

* Set `CMAKE_AUTOMOC` flag `ON` if `CMake` needs to handle the `Qt moc` preprocessor properly. (I believe this flag tells the `moc` (meta object compiler) to parse `Q_OBJECT`, `Q_GADGET` and / or similar macros.) Virtually all `Qt` projects will need this flag to be turned on.

* Set `CMAKE_AUTOUIC` if you have the ` .ui` files (perhaps created from Qt Designer). You also have to add the corresponding header file in the required cpp files for each `.ui` files. For example, if you have a `mainwindow.ui` file, then in your `mainwindow.cpp` file, you must have `#include "ui_mainwindow.h"`. This is understandable because the automatic `uic` (UI compiler??) actually converts the `.ui` file to a header file of that name. This is equivalent to creating the UI in Qt-Designer and performing "Show Code" and exporting the code to a header file directly. There's nothing mysterious about this step.

* Set `CMAKE_AUTORCC` flag if you have `.qrc` (resource) files and need to automatically handle the code generator. The `.qrc` file may have information about assets such as JPEGs or QML files and what not. Setting this flag converts the static image assets or qml descriptions to loads of hex values in a generated cpp file as resource data.

It is worth noting that each of the above cmake flags can be replaced by corresponding `CMake` macros for qt. namely `QT5_WRAP_CPP()`, `QT5_WRAP_UI()` and `QT5_ADD_RESOURCES()`.

For example let's consider a project with following folder structure.
```
- Root
    - resources
        - something.jpg
    - CMakeList.txt
    - main.cpp
    - mainwindow.h
    - mainwindow.cpp
    - mainwindow.ui
    - res.qrc
```

And we have class MainWindow defined in `mainwindow.h` that has all the `Q_OBJECT` and `slots` and stuffs.

Then the following two versions of `CMakeLists.txt` does the same thing.

**Using CMake flags**

```cmake
cmake_minimum_required(VERSION 3.8.2)

project(helloworld)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(helloworld main.cpp mainwindow.cpp mainwindow.ui resources.qrc)

target_link_libraries(helloworld Qt5::Widgets)

```

**Using CMake Macros for Qt**

```cmake
cmake_minimum_required(VERSION 3.8.2)

project(helloworld)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

QT5_WRAP_CPP(MOC_FILES
    mainwindow.h
)

QT5_WRAP_UI(UI_SRC
    mainwindow.ui
)

QT5_ADD_RESOURCES(RES_SRC
  resources.qrc
)

add_executable(helloworld ${MOC_FILES} main.cpp mainwindow.cpp ${UI_SRC} ${RES_SRC})

target_link_libraries(helloworld Qt5::Widgets)
```

* In addition to all these, sometimes, you might need to make sure that the `CMAKE_PREFIX_PATH` is pointing to directory where your `Qt5Config.cmake` is located in your `Qt5` installation.
