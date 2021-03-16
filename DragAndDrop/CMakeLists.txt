cmake_minimum_required(VERSION 3.15)
project(DragAndDrop)

set(CMAKE_CXX_STANDARD 14)

add_executable(DragAndDrop main.cpp)

target_link_libraries(DragAndDrop sfml-graphics sfml-window sfml-system)