cmake_minimum_required(VERSION 3.15)
project(learningSFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(learningSFML
        test2.cpp)

target_link_libraries(learningSFML sfml-graphics sfml-window sfml-system)
