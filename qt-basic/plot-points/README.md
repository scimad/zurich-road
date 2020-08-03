# Graph Plotter using QT and cmake

(*This project uses the example from the author of the  **QCustomPlot** library.*)

In this project, I have used cmake to build a plotter application with qcustomplot library (Extension for Qt C++ library for plotting related applications). The process looks daunting at first, and after some time of meticulous attention and effort, I got the compilation to work with cmake.

Here are few things to remember while compiling Qt (C++) applications:

### In CMakeLists.txt

* the `CMAKE_AUTOMOC` flag should be on.
* the `CMAKE_PREFIX_PATH` should point to directory where your `Qt5Config.cmake` is located in your `Qt5` installation
* If you have a `.ui` file, you should use `qt5_wrap_ui` to list it as source so that it could be converted into a header file.
* The `MOC` (meta object compiler) needs to know of the header files. So, all the header files are added to the `add_executable` command list. There probably is some better way to do this as well.
* The files listed under `qt5_wrap_ui` are also added to the `add_executable` command's list.
* I also modified the `mainwindow.ui` to relocate the `qcustomplot.h` file, which happens to be in my `include` directory. (I am not sure but since my `include` folder is already added to the `include_directories`, I can just add the filename (instead of relative / full path) of `qcustomplot.h` inside the `<header>` tag in the `mainwindow.ui`).
