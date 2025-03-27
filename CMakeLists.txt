# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(LinkedList C)

# Set C standard
set(CMAKE_C_STANDARD 11)

# Include directories
include_directories(include)

# Add the cmake directory to CMAKE_MODULE_PATH
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Find and include CUnit
find_package(CUnit REQUIRED)

# Add main executable
add_executable(LinkedList
        src/main.c
        src/Data.c
        src/LinkedList.c
        src/ErrorHandler.c
        src/Node.c
)

# Add test executable
add_executable(runTests
        test/test_runner.c
        test/test_node.c
        src/Node.c
        src/Data.c
        src/ErrorHandler.c
)

# Link CUnit to test executable
target_link_libraries(runTests ${CUNIT_LIBRARIES})
include_directories(${CUNIT_INCLUDE_DIRS})
