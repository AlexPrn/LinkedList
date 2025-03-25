cmake_minimum_required(VERSION 3.30)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
#include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(LinkedList
        src/main.c
        src/Data.c
        src/LinkedList.c
        src/ErrorHandler.c
        src/Node.c
)
