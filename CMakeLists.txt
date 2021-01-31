cmake_minimum_required(VERSION 3.17)
project(triangles)

set(CMAKE_CXX_STANDARD 17)

add_executable(triangles main.cpp geometry_objects.h geometry_objects.cpp intersection.cpp intersection.h)
