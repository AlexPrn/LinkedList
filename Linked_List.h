//
// Created by o_partizanos on 21/3/2025.
//

#include "Data.h"
#include "Node.h"
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList{
  Node* head;
  Node* tail;
} LinkedList;


LinkedList* init_linked_list();
void free_linked_list(LinkedList*);


#endif //LINKEDLIST_H
