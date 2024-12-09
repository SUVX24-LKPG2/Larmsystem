cmake_minimum_required(VERSION 3.12.0)
project(larmsystem VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "main.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(larmsystem ${SOURCES})

target_link_libraries(larmsystem sqlite3)

