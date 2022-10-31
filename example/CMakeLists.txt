cmake_minimum_required(VERSION 3.7)

project(app VERSION 0.0.1 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)

set(sources main.cpp)

add_executable(app)
target_compile_options(app PRIVATE -Werror -pedantic-errors -Wall -Wextra -Wpedantic)
target_sources(app PRIVATE ${sources})
target_link_libraries(app PRIVATE finiteAutomata)