cmake_minimum_required(VERSION 3.23)
project(cast_from_string)

set(CMAKE_CXX_STANDARD 14)

add_executable(cast_from_string main.cpp FromString.h CastException.h CastException.cpp)
