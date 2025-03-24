//
// Created by o_partizanos on 23/3/2025.
//

#include <stdlib.h>
#include <stdio.h>
#include "Linked_List.h"
#include "Data.h"
#define EXIT_FAILURE 1

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

void handle_memory_allocation_failure(const char* type);

void handle_out_of_bounds_error(LinkedList *linked_list, Data *data);

#endif //ERRORHANDLER_H
