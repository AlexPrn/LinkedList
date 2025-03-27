//
// Created by o_partizanos on 27/3/2025.
//

#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/Node.h"

void test_get_new_node();
void test_is_not_null();
void test_attach_data_to_node();


void add_node_tests();

void add_node_tests(){
  CU_pSuite suite = CU_add_suite("node_tests", 0, 0);
  CU_add_test(suite, "test_get_new_node", test_get_new_node);
  CU_add_test(suite, "test_is_not_null", test_is_not_null);
  CU_add_test(suite, "test_attach_data_to_node", test_attach_data_to_node);
}

void test_get_new_node(){
  Node* node = get_new_node();
  CU_ASSERT_PTR_NOT_NULL(node);
  CU_ASSERT_PTR_NULL(node->next);
  CU_ASSERT_PTR_NULL(node->data);
  free(node);
}

void test_is_not_null(){
  Node* node = get_new_node();
  CU_ASSERT_TRUE(is_not_null(node));
  CU_ASSERT_FALSE(is_not_null(NULL));
  node = NULL;
  CU_ASSERT_FALSE(is_not_null(node));
  free(node);
}

void test_attach_data_to_node(){
  Node *node = get_new_node();
  Data mock_data;
  attach_data_to_node(node, &mock_data);
  CU_ASSERT_PTR_EQUAL(node->data, &mock_data);
  free(node);
}

