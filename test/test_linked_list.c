//
// Created by o_partizanos on 28/3/2025.
//

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/LinkedList.h"
#include "../include/ErrorHandler.h"

// static int out_of_bounds_handler_called = 0;
// void handle_out_of_bounds_error(LinkedList* linked_list, Node* node) {
//   (void) linked_list;
//   (void) node;
//   out_of_bounds_handler_called = 1;
// }


void test_init_linked_list();
void test_is_empty();
void test_add_at_head();
void test_add_at_tail();
void test_add_at_index();                  // Happy Day test
void test_add_at_index_out_of_bounds();    // Error handling test
void test_delete_at_head();
void test_delete_at_tail();
void test_delete_at_index();
// void test_free_linked_list();


void add_linked_list_tests();

void add_linked_list_tests(){
  CU_pSuite suite = CU_add_suite("linked_list", 0, 0);
  CU_add_test(suite, "test_init_linked_list", test_init_linked_list);
  CU_add_test(suite, "test_is_empty", test_is_empty);
  CU_add_test(suite, "test_add_at_head", test_add_at_head);
  CU_add_test(suite, "test_add_at_tail", test_add_at_tail);
  CU_add_test(suite, "test_add_at_index", test_add_at_index);
  CU_add_test(suite, "test_delete_at_head", test_delete_at_head);
  CU_add_test(suite, "test_delete_at_tail", test_delete_at_tail);
  CU_add_test(suite, "test_delete_at_index", test_delete_at_index);
  // CU_add_test(suite, "test_add_at_index for out_of_bounds handle", test_add_at_index_out_of_bounds);
  // CU_add_test(suite, "test_free_linked_list", test_free_linked_list);
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

void test_add_at_index() {
  LinkedList* list = init_linked_list();

  Node* node1 = get_new_node();
  add_at_index(list, node1, 0);
  CU_ASSERT_PTR_EQUAL(list->head, node1);
  CU_ASSERT_PTR_EQUAL(list->tail, node1);

  Node* node2 = get_new_node();
  add_at_index(list, node2, 1);
  CU_ASSERT_PTR_EQUAL(list->tail, node2);
  CU_ASSERT_PTR_EQUAL(list->head->next, node2);

  Node* node3 = get_new_node();
  add_at_index(list, node3, 1);
  CU_ASSERT_PTR_EQUAL(list->head->next, node3);
  CU_ASSERT_PTR_EQUAL(node3->next, node2);

  free_linked_list(list);
}

// void test_add_at_index_out_of_bounds() {
//   LinkedList* list = init_linked_list();
//   add_empty_node_at_head(list);
//   add_empty_node_at_head(list);
//   Node* node = get_new_node();
//
//   out_of_bounds_handler_called = 0; // Reset counter
//   add_at_index(list, node, 100);
//
//   CU_ASSERT_EQUAL(out_of_bounds_handler_called, 1);
//
//   free_linked_list(list);
// }

void test_delete_at_head() {
  LinkedList* list = init_linked_list();

  add_empty_node_at_head(list);
  add_empty_node_at_head(list);
  Node* second_node = list->head->next;

  delete_at_head(list);
  CU_ASSERT_PTR_EQUAL(list->head, second_node);

  delete_at_head(list);
  CU_ASSERT_TRUE(is_empty(list));

  free_linked_list(list);
}

void test_delete_at_tail() {
  LinkedList* list = init_linked_list();

  add_empty_node_at_head(list);
  add_empty_node_at_head(list);
  Node* first_node = list->head;

  delete_at_tail(list);
  CU_ASSERT_PTR_EQUAL(list->tail, first_node);

  delete_at_tail(list);
  CU_ASSERT_TRUE(is_empty(list));

  free_linked_list(list);
}

void test_delete_at_index() {
  LinkedList* list = init_linked_list();

  add_empty_node_at_head(list);
  add_empty_node_at_head(list);
  add_empty_node_at_head(list);
  Node* third_node = list->head->next->next;

  delete_at_index(list, 1);
  CU_ASSERT_PTR_EQUAL(list->head->next, third_node);

  // Case: out-of-bounds index (should be ignored)
  delete_at_index(list, 5);
  CU_ASSERT_PTR_NOT_NULL(list->head);
  CU_ASSERT_PTR_NULL(get_node_at_index(list, 5));
  // END Case: out-of-bounds index (should be ignored)

  delete_at_index(list, 0);
  CU_ASSERT_PTR_EQUAL(list->head, third_node);

  delete_at_index(list, 0);
  CU_ASSERT_TRUE(is_empty(list));

  free_linked_list(list);
}

