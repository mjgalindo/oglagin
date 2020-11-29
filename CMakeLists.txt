cmake_minimum_required(VERSION 3.13)

project(oglagin)

add_subdirectory(libs)

add_executable(oglagin oglagin.cpp)
target_link_libraries(oglagin glfw glad)