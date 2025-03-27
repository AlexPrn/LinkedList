//
// Created by o_partizanos on 21/3/2025.
//

#include "../include/Node.h"
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList{
  Node* head;
  Node* tail;
} LinkedList;


LinkedList* init_linked_list();
void free_linked_list(LinkedList*);

int is_empty(LinkedList*);

void add_empty_node_at_head(LinkedList* linked_list);
void add_at_head(LinkedList *linked_list, Node *node);
void add_empty_node_at_tail(LinkedList *linked_list);
void add_at_tail(LinkedList *linked_list, Node *node);
void add_new_at_index(LinkedList *linked_list, int index);
void add_at_index(LinkedList *linked_list, Node *node, int index);

Node* get_node_at_index(LinkedList *linked_list, int index);

void delete_at_head(LinkedList *linked_list);
void delete_at_tail(LinkedList *linked_list);
void delete_at_index(LinkedList *linked_list ,int index);

void print_linked_list(LinkedList* linked_list);

#endif //LINKEDLIST_H
