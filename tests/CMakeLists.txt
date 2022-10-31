cmake_minimum_required(VERSION 3.7)
project(tests LANGUAGES C CXX)

find_package(Boost)

set(sources main.cpp)

add_executable(tests)
include_directories(${Boost_INCLUDE_DIRS})
target_compile_options(tests PRIVATE -Werror -pedantic-errors -Wall -Wextra -Wpedantic)
target_sources(tests PRIVATE ${sources})
target_link_libraries(tests PRIVATE finiteAutomata Boost)