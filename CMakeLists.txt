cmake_minimum_required(VERSION 3.2...3.5 FATAL_ERROR)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(PROJECT_NAME HW-dpcpp-2.1)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} include/main.hpp src/main.cpp)

add_library(TextLib SHARED include/Text.hpp src/Text.cpp)

target_link_libraries(${PROJECT_NAME} TextLib)
