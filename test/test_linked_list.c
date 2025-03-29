//
// Created by o_partizanos on 28/3/2025.
//


#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/LinkedList.h"


void test_init_linked_list();
void test_is_empty();
void test_add_at_head();
void test_add_at_tail();

void add_linked_list_tests();

void add_linked_list_tests(){
  CU_pSuite suite = CU_add_suite("linked_list", 0, 0);
  CU_add_test(suite, "test_init_linked_list", test_init_linked_list);
  CU_add_test(suite, "test_is_empty", test_is_empty);
  CU_add_test(suite, "test_add_at_head", test_add_at_head);
  CU_add_test(suite, "test_add_at_tail", test_add_at_tail);
}


void test_init_linked_list(){

  LinkedList* list = init_linked_list();
  CU_ASSERT_PTR_NOT_NULL(list);
  CU_ASSERT_PTR_NULL(list->head);
  CU_ASSERT_PTR_NULL(list->tail);
  free(list);
}

void test_is_empty() {
  LinkedList* list = init_linked_list();
  CU_ASSERT_TRUE(is_empty(list));

  Node* node = get_new_node();
  add_at_head(list, node);
  CU_ASSERT_FALSE(is_empty(list));

  free_linked_list(list);
}

void test_add_at_head() {
  LinkedList* list = init_linked_list();
  Node* node = get_new_node();

  add_at_head(list, node);
  CU_ASSERT_PTR_EQUAL(list->head, node);
  CU_ASSERT_PTR_EQUAL(list->tail, node);
  CU_ASSERT_PTR_NULL(list->head->next);

  Node* node2 = get_new_node();
  add_at_head(list, node2);
  CU_ASSERT_PTR_EQUAL(list->head, node2);
  CU_ASSERT_PTR_EQUAL(list->head->next, node);

  free_linked_list(list);
}

void test_add_at_tail() {
  LinkedList* list = init_linked_list();
  Node* node = get_new_node();
  add_at_tail(list, node);
  CU_ASSERT_PTR_EQUAL(list->tail, node);
  CU_ASSERT_PTR_EQUAL(list->head, node);
  CU_ASSERT_PTR_NULL(list->tail->next);

  Node* node2 = get_new_node();
  add_at_tail(list, node2);
  CU_ASSERT_PTR_EQUAL(list->tail, node2);
  CU_ASSERT_PTR_EQUAL(list->head->next, node2);

}

