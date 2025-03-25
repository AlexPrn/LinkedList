//
// Created by o_partizanos on 21/3/2025.
//

#include <stdio.h>
#include "../include/Data.h"
#include "../include/ErrorHandler.h"
#include "../include/LinkedList.h"

LinkedList* init_linked_list() {
    LinkedList* new_linked_list = malloc(sizeof(LinkedList));

    if (new_linked_list == NULL) {
        handle_memory_allocation_failure("linked_list");
    }

    new_linked_list->head = NULL;
    new_linked_list->tail = NULL;
    return new_linked_list;
}
void free_linked_list(LinkedList* linked_list) {
    Node* current = linked_list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    linked_list->head = NULL;
    linked_list->tail = NULL;
    free(linked_list);
}

int is_empty(LinkedList* linked_list){
    return linked_list->head == NULL && linked_list->tail == NULL;
}


void add_empty_node_at_head(LinkedList* linked_list) {
    Node *new_node = get_new_node();  // Create a fresh new node
    add_at_head(linked_list, new_node);
}

void add_at_head(LinkedList *linked_list, Node *node) {

    if (is_empty(linked_list))
        linked_list->tail = node;
    node->next = linked_list->head;
    linked_list->head = node;

}

void add_empty_node_at_tail(LinkedList *linked_list) {
    Node *new_node = get_new_node();
    add_at_tail(linked_list, new_node);
}

void add_at_tail(LinkedList *linked_list, Node *node) {

    if (is_empty(linked_list)) {
        linked_list->head = node;
        linked_list->tail = node;
    } else {
        linked_list->tail->next = node;
        linked_list->tail = node;
    }
    node->next = NULL;
}

Node* get_node_at_index(LinkedList *linked_list, int index) {
    if (index < 0) {
        printf("Negative value is not valid, returning NULL\n");
        return NULL;
    }

    Node *current = linked_list->head;
    int count = 0;

    while (current != NULL) {
        if (count == index) {
            return current;
        }
        current = current->next;
        count++;
    }

    return NULL;
}

void add_new_at_index(LinkedList *linked_list, int index) {
    Node *new_node = get_new_node();
    add_at_index(linked_list, new_node, index);
}

void add_at_index(LinkedList *linked_list, Node* node ,int index) {
    if (index == 0) {
        add_at_head(linked_list, node);
        return;
    }

    Node *prev = get_node_at_index(linked_list, index - 1);

    if (prev == NULL) {
        handle_out_of_bounds_error(linked_list, node);
        return;
    }

    if (prev->next == NULL) {
        add_at_tail(linked_list, node);
        return;
    }

    node->next = prev->next;
    prev->next = node;
}

void delete_at_head(LinkedList *linked_list) {

    if (is_empty(linked_list)) {
        handle_null_object_error("Linked List");
        return;
    }

    Node *temp = linked_list->head;
    linked_list->head = linked_list->head->next;

    // If the list had only one node, update the tail as well
    if (linked_list->head == NULL) {
        linked_list->tail = NULL;
    }

    free(temp);
}

void delete_at_tail(LinkedList *linked_list) {
    if (is_empty(linked_list)) {
        handle_null_object_error("Linked List");;
        return;
    }

    if (linked_list->head == linked_list->tail) {  // Only one node in the list
        free(linked_list->head);
        linked_list->head = NULL;
        linked_list->tail = NULL;
        return;
    }

    // Find the second-to-last node
    Node *prev = linked_list->head;
    while (prev->next != linked_list->tail) {
        prev = prev->next;
    }

    free(linked_list->tail);
    prev->next = NULL;
    linked_list->tail = prev;


}

void delete_at_index(LinkedList *linked_list, int index) {
    if (index < 0) {
        printf("Invalid index, please provide a positive integer.\n");
        return;
    }

    if (is_empty(linked_list)) {
        handle_null_object_error("Linked List");
        return;
    }

    if (index == 0) {
        delete_at_head(linked_list);
        return;
    }

    Node *prev = get_node_at_index(linked_list, index - 1);

    if (prev == NULL || prev->next == NULL) {
        printf("The node you are trying to delete is out of bounds. Nothing to delete.\n");
        return;
    }

    Node *to_delete = prev->next;

    if (to_delete == linked_list->tail) {
        delete_at_tail(linked_list);
        return;
    }

    prev->next = to_delete->next;
    free(to_delete);
    to_delete = NULL;

}

