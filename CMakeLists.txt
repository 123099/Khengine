cmake_minimum_required(VERSION 3.17)
project(Khengine)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(externals/glfw)
include_directories(externals/glfw/include)

add_executable(Khengine main.cpp)