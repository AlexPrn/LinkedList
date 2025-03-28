//
// Created by o_partizanos on 28/3/2025.
//


#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/LinkedList.h"


void test_init_linked_list();

void add_linked_list_tests();

void add_linked_list_tests(){
  CU_pSuite suite = CU_add_suite("linked_list", 0, 0);
  CU_add_test(suite, "test_init_linked_list", test_init_linked_list);
}


void test_init_linked_list(){

  LinkedList* list = init_linked_list();
  CU_ASSERT_PTR_NOT_NULL(list);
  CU_ASSERT_PTR_NULL(list->head);
  CU_ASSERT_PTR_NULL(list->tail);
  free(list);
}


