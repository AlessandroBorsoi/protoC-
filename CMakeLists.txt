cmake_minimum_required(VERSION 3.7)
project(protoC++)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(dependencies/glfw)

include_directories(
        "dependencies/glew/include"
        "dependencies/glfw/include"
        "dependencies/glm")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(protoC++ ${SOURCE_FILES})