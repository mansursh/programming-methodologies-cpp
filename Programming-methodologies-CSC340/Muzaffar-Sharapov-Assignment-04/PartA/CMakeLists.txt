cmake_minimum_required(VERSION 3.20)
project(Assignment_04_Part_B)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_04_Part_B
        BagInterface.h
        Include.h
        LinkedBag.cpp
        LinkedBag.h
        LinkedBag340.cpp
        LinkedBagClient340.cpp
        Node.cpp
        Node.h)
