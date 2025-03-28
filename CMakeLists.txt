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

# Manually specify CUnit paths
set(CUNIT_LIB_DIR "/usr/lib/x86_64-linux-gnu")
set(CUNIT_INCLUDE_DIR "/usr/include")

# Find and include CUnit
find_package(CUnit REQUIRED)

# Main executable
add_executable(LinkedList
        src/main.c
        src/Data.c
        src/LinkedList.c
        src/ErrorHandler.c
        src/Node.c
)

# Test executable
add_executable(runTests
        test/test_runner.c
        test/test_node.c
        src/Node.c
        src/Data.c
        src/ErrorHandler.c
        src/LinkedList.c
        # Future test suites
        # test/test_linkedlist.c
        # test/test_errorhandler.c
)

# Link CUnit and include necessary directories
target_include_directories(runTests PRIVATE ${CUNIT_INCLUDE_DIR})
target_link_libraries(runTests ${CUNIT_LIB_DIR}/libcunit.so)
