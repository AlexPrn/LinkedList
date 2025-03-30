# FindCUnit.cmake
# CMake module to find CUnit library

find_path(CUNIT_INCLUDE_DIR
        NAMES CUnit/CUnit.h
        PATHS
        $ENV{CUNIT_ROOT}/include  # Allow users to specify CUNIT_ROOT
        ${CMAKE_PREFIX_PATH}/include
        /usr/include
        /usr/local/include
        /opt/homebrew/include
)

find_library(CUNIT_LIBRARY
        NAMES cunit
        PATHS
        $ENV{CUNIT_ROOT}/lib
        ${CMAKE_PREFIX_PATH}/lib
        /usr/lib
        /usr/local/lib
        /opt/homebrew/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CUnit DEFAULT_MSG CUNIT_INCLUDE_DIR CUNIT_LIBRARY)

if(CUNIT_FOUND)
    set(CUNIT_LIBRARIES ${CUNIT_LIBRARY})
    set(CUNIT_INCLUDE_DIRS ${CUNIT_INCLUDE_DIR})
    message(STATUS "Found CUnit: ${CUNIT_LIBRARY}")
else()
    set(CUNIT_LIBRARIES "")
    set(CUNIT_INCLUDE_DIRS "")
    message(WARNING "CUnit not found. Tests may not compile.")
endif()

mark_as_advanced(CUNIT_INCLUDE_DIR CUNIT_LIBRARY)
