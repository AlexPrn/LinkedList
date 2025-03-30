//
// Created by o_partizanos on 23/3/2025.
//

#include "../include/LinkedList.h"
#define EXIT_FAILURE 1

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

void handle_memory_allocation_failure(const char* type);

// Function pointer for handling out-of-bounds errors
typedef void (*OutOfBoundsHandler)(LinkedList* linked_list, Node* node);

// Expose a setter function to allow overriding the handler
void set_out_of_bounds_handler(OutOfBoundsHandler handler);


void handle_out_of_bounds_error(LinkedList* linked_list, Node* node);


void handle_null_object_error(const char* type);

#endif //ERRORHANDLER_H
