cmake_minimum_required(VERSION 3.5)

project(Box)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Box main.cpp Entry.cpp Boxes.cpp)

target_link_libraries(Box Qt5::Widgets)
