//
// Created by o_partizanos on 23/3/2025.
//

#include "../include/LinkedList.h"
#define EXIT_FAILURE 1

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

void handle_memory_allocation_failure(const char* type);


void handle_out_of_bounds_error(LinkedList* linked_list, Node* node);


void handle_null_object_error(const char* type);

#endif //ERRORHANDLER_H
