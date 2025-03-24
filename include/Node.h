//
// Created by o_partizanos on 21/3/2025.
//

#include "Data.h"
#include "ErrorHandler.h"

#ifndef NODE_H
#define NODE_H


typedef struct Node{
    Data *data;
    struct Node* next;
} Node;

Node *get_new_node();

int is_not_null(Node *node);

void attach_data_to_node(Node *node, Data *data);

#endif //NODE_H

