//
// Created by o_partizanos on 30/3/2025.
//

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/ErrorHandler.h"
#include "../include/LinkedList.h"

static int custom_handler_called = 0;
static void custom_out_of_bounds_handler(LinkedList* linked_list, Node* node) {
    (void)linked_list;
    (void)node;
    custom_handler_called = 1;
}

void test_set_out_of_bounds_handler();
void test_handle_null_object_error();

void add_error_handler_tests();

void add_error_handler_tests(){
    CU_pSuite suite = CU_add_suite("error_handler", 0, 0);
    CU_add_test(suite, "test_set_out_of_bounds_handler", test_set_out_of_bounds_handler);
    CU_add_test(suite, "test_handle_null_object_error", test_handle_null_object_error);
}

void test_set_out_of_bounds_handler(){
    custom_handler_called = 0;
    set_out_of_bounds_handler(custom_out_of_bounds_handler);
    handle_out_of_bounds_error(NULL, NULL);
    CU_ASSERT_EQUAL(custom_handler_called, 1);
}

void test_handle_null_object_error(){
    FILE* original_stdout = stdout;
    FILE* temp_stdout = tmpfile();
    stdout = temp_stdout;

    handle_null_object_error("LinkedList");

    fflush(stdout);
    fseek(temp_stdout, 0, SEEK_SET);

    char buffer[256];
    fgets(buffer, sizeof(buffer), temp_stdout);
    CU_ASSERT_STRING_EQUAL(buffer, "Cannot operate over NULL LinkedList\n");

    stdout = original_stdout;
    fclose(temp_stdout);
}

