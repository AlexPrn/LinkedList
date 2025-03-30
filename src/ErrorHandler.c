//
// Created by o_partizanos on 23/3/2025.
//

#include <stdio.h>
#include "../include/Data.h"
#include "../include/ErrorHandler.h"
#include "../include/LinkedList.h"
#include "../include/ErrorHandler.h"

void handle_memory_allocation_failure(const char* type){

    fprintf(stderr, "Memory allocation failed for %s\n", type);
    exit(EXIT_FAILURE);
}



// Default handler function
static void default_out_of_bounds_handler(LinkedList *linked_list, Node *node);

// Function pointer initialized to the default handler
static OutOfBoundsHandler out_of_bounds_handler = default_out_of_bounds_handler;

// Function to set a custom out-of-bounds handler
void set_out_of_bounds_handler(OutOfBoundsHandler handler) {
    if (handler) {
        out_of_bounds_handler = handler;
    }
}

// This function remains unchanged but now delegates to the function pointer
void handle_out_of_bounds_error(LinkedList *linked_list, Node *node) {
    out_of_bounds_handler(linked_list, node);
}

void default_handle_out_of_bounds_error(LinkedList *linked_list, Node *node) {
    int choice;

    while (1) {
        printf("Index out of bounds. Choose an action:\n");
        printf("1. Ignore and do nothing.\n");
        printf("2. Insert at head.\n");
        printf("3. Insert at tail.\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Operation ignored.\n");
            return;
            case 2:
                add_at_head(linked_list, node);
            printf("Inserted at head.\n");
            return;
            case 3:
                add_at_tail(linked_list, node);
            printf("Inserted at tail.\n");
            return;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n"); //Insecure, will clear it later
        }
    }
}

void handle_null_object_error(const char* type) {
    printf("Cannot operate over NULL %s\n", type);
}

