cmake_minimum_required(VERSION 3.15)
project(MMM)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MMM
        Cancellation.cpp
        Cancellation.h
        Definitions.h
        Events.cpp
        Events.h
        Formulation.cpp
        Formulation.h
        LinkedList.h
        LinkedQueue.h
        ll.cpp
        Mission.cpp
        Mission.h
        Node.h
        Promotion.cpp
        Promotion.h
        Rover.cpp
        Rover.h
        Station.cpp
        Station.h
        MMM.cpp)
