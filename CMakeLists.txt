cmake_minimum_required(VERSION 3.21)
project(Algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
