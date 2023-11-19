cmake_minimum_required(VERSION 3.7)

project(finiteAutomata VERSION 0.0.2 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 17)

add_library(finiteAutomata STATIC)
#add_library(lib::lib ALIAS lib)

target_compile_options(finiteAutomata PRIVATE -Werror -pedantic-errors -Wall -Wextra -Wpedantic)

option(FA_BUILD_TESTS "Build tests" OFF)
option(FA_BUILD_EXAMPLE "Build example" OFF)

file(GLOB sources "src/*.cpp")
file(GLOB includes "include/*.hpp")
include_directories(include)

target_sources(finiteAutomata PRIVATE ${sources})

if(FA_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(FA_BUILD_EXAMPLE)
    add_subdirectory(example)
endif()