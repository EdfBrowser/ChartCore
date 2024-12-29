cmake_minimum_required(VERSION 3.29)

project(Chart)

enable_language(C CXX)

set(CMAKE_CXX_STANDARD 14 CACHE STRING "C++ standard to conform to")
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    message(STATUS "Setting Visual Studio specific flags for the entire build")
    add_compile_options(/W3 /WX)
    add_link_options(/WX)
endif()


add_subdirectory(Core)
add_subdirectory(Test)