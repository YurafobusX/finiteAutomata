cmake_minimum_required(VERSION 3.7)

project(finiteAutomata VERSION 0.0.1 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)

add_library(finiteAutomata);
#add_library(lib::lib ALIAS lib)

#add_executable(main)
#target_compile_options(main PRIVATE -Werror -pedantic-errors -Wall -Wextra -Wpedantic)

#file(GLOB sources "src/*.cpp")
#file(GLOB includes "include/*.hpp")
#include_directories(include)

#target_sources(main PRIVATE ${sources} ${includes})