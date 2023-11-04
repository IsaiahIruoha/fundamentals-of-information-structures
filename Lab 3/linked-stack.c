#include <stdlib.h>
#include "stack.h"

struct stack_node {
    char value; 
    struct stack_node* next; 
};

struct stack {
    // Null if the stack is empty.
    struct stack_node* head;
};

stack_ptr stack_new() {
    stack_ptr s = malloc(sizeof(struct stack));
    s->head = NULL;
    return s;
}

void stack_free(stack_ptr s) {
    while (s->head != NULL){ // While the stack is not empty
        struct stack_node* temp = s->head; // Create a temporary pointer to the top of the stack
        s->head = s->head->next; // "Metaphorically remove the top plate"
        if (temp->value) { // Check if the previous top node had any values
            free(temp->value); // If it did free the values
        }
        free(temp); // Free the entire node
    }
    free(s);
}

void stack_push(stack_ptr s, char c) {
    struct stack_node* new_node = malloc(sizeof(struct stack_node)); // Allocate memory for the new node
    new_node->value = c; // Set the value of the new node
    new_node->next = s->head; // Set the new node to point to the current top
    s->head = new_node; // Set the current to be the new node
}

bool stack_pop(stack_ptr s, char *out) {
    if (s->head == NULL) { // Check if the stack exists
        return false; // Return false if it does not exist
    }
    struct stack_node* temp = s->head; // Create a temporary pointer to a stack_node storing the memory address of the current head
    *out = s->head->value; // Dereference the character storage location, assign it to store the value at the head node
    s->head = s->head->next; // Change the head node to the next node
    free(temp); // Free the previous head node
    return true; // Return true to show that a pop has occured 
}
