cmake_minimum_required(VERSION 4.3)
project(STRING)

set(CMAKE_CXX_STANDARD 26)

add_executable(STRING main.cpp
        Library/String/MAIN/string.h
        Library/String/MAIN/string.cpp
        Library/String/Error/IndexOutofReangeError/IndexOutofrange.h
        Library/String/Error/IndexOutofReangeError/IndexOutofrange.cpp)
