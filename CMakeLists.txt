cmake_minimum_required(VERSION 4.0.0)

include(cmake/init.cmake)

project(
    dartvm
    VERSION 0.0.1
    LANGUAGES CXX
)

add_subdirectory(source/api)
add_subdirectory(source/bin)
add_subdirectory(source/platform)
add_subdirectory(source/utils)
add_subdirectory(source)