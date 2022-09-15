cmake_minimum_required(VERSION 2.6)
project(Snakesim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++17 -pthread")
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
file(GLOB SOURCES_TEST "test/test.cpp" "src/Board.cpp" "src/RoutePlanner.cpp" "src/Simulation.cpp" "src/Snake.cpp")

add_executable(snakesim ${SOURCES})
add_executable(test ${SOURCES_TEST})

target_link_libraries(snakesim sfml-graphics sfml-system sfml-window)
target_compile_options(snakesim PRIVATE -Wall -Wextra)

target_link_libraries(test sfml-graphics sfml-system sfml-window)
target_compile_options(test PRIVATE -Wall -Wextra)
