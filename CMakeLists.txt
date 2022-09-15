cmake_minimum_required(VERSION 2.6)
project(Snakesim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17 -pthread")
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(snakesim ${SOURCES})

target_link_libraries(snakesim sfml-graphics sfml-system sfml-window)
target_compile_options(snakesim PRIVATE -Wall -Wextra)