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

#endif //NODE_H

