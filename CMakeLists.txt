cmake_minimum_required(VERSION 2.6)
project(Snake)

set(CMAKE_CXX_STANDARD 17)


file(GLOB SOURCES "src/*.cpp")

find_package(libsfml-dev REQUIRED)
add_executable(snake ${SOURCES})

target_link_libraries(snake sfml-graphics sfml-system sfml-window)