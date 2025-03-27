//
// Created by o_partizanos on 27/3/2025.
//

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>


// Declare the functions that add the test suites
void add_node_tests();

int main() {
    CU_initialize_registry();

    // Add all test suites
    add_node_tests();

    // Set the CUnit mode
    CU_basic_set_mode(CU_BRM_VERBOSE);

    // Run the tests
    CU_basic_run_tests();

    // Cleanup the CUnit registry
    CU_cleanup_registry();
    return 0;
}