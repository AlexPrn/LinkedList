//
// Created by o_partizanos on 21/3/2025.
//

#include "Data.h"

#ifndef NODE_H
#define NODE_H


typedef struct Node{
    Data data;
    struct Node* next;
} Node;

#endif //NODE_H
