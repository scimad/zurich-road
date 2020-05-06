cmake_minimum_required(VERSION 2.8)

project (MyNN DESCRIPTION "My Neural Network Library")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(
    mynn SHARED
    src/perceptron.cpp
    )
