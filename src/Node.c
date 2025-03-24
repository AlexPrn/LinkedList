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

int is_not_null(Node *node) {
    return node != NULL;
}

void attach_data_to_node(Node *node, Data *data) {
    if(is_not_null(node)){
        node->data = data;
    }
    else {
        handle_null_object_error("Node");
    }
}

