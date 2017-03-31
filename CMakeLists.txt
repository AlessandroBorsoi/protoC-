cmake_minimum_required(VERSION 3.7)
project(protoC++)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

if (NOT EXISTS ${CMAKE_SOURCE_DIR}/dependencies/gl3w/src/gl3w.c)
    execute_process(COMMAND python ${CMAKE_SOURCE_DIR}/dependencies/gl3w/gl3w_gen.py)
endif ()
add_subdirectory(dependencies/gl3w)
add_library(gl3w.c ${CMAKE_SOURCE_DIR}/dependencies/gl3w/src/gl3w.c)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(dependencies/glfw)

add_subdirectory(dependencies/glm)

include_directories(
        "include"
        "dependencies/gl3w/include"
        "dependencies/glfw/include"
        "dependencies/glm")

file(GLOB PROJECT_HEADERS include/*.h)
file(GLOB PROJECT_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} gl3w.c glfw)