//
// Created by o_partizanos on 23/3/2025.
//

#include "Node.h"

Node *get_new_node(){
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        handle_memory_allocation_failure("Node");
    }
    new_node->next = NULL;
    new_node->data = NULL;
    return new_node;
}

