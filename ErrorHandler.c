//
// Created by o_partizanos on 23/3/2025.
//

#include "ErrorHandler.h"

void handle_memory_allocation_failure(const char* type){

    fprintf(stderr, "Memory allocation failed for %s\n", type);
    exit(EXIT_FAILURE);
}

