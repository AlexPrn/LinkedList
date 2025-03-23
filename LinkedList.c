//
// Created by o_partizanos on 21/3/2025.
//


#include "Linked_List.h"
#include "ErrorHandler.h"

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
    free(linked_list);
}

