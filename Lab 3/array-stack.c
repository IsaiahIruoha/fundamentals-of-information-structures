#include <stdlib.h>
#include "stack.h"

struct stack {
    // Points to dynamically allocated array of size 'capacity', or is NULL.
    char *data;
    // The capacity of the array.
    size_t capacity;
    // The number of entries currently in the stack.
    size_t length;
};

stack_ptr stack_new() {
    stack_ptr s = malloc(sizeof(struct stack));
    s->data = NULL;
    s->capacity = 0;
    s->length = 0;
    return s;
}

void stack_free(stack_ptr s) {
    if (s->data != NULL)
        free(s->data);
    free(s);
}

void stack_push(stack_ptr s, char c) {
    if (s == NULL) { // Check if the stack is initialized
        return;
    }

    if (s->length >= s->capacity) { // If the length is greater or equal to the capacity
        s->capacity *= 2; // Expand the capacity by a multiple of two
        if (s->capacity == 0) {
            s->capacity = 10; // No initial capacity is provided so assumption of an increase in 10 is used
        }
        s->data = (char*)realloc(s->data, s->capacity * sizeof(char)); // Adjust the dynamically allocated memory to reflect the new capacity
    }
    s->data[s->length++] = c; // Assign the index at the current length to hold C, then increment the length
    return; 
}

bool stack_pop(stack_ptr s, char *out) {
    if (s == NULL || s->length <= 0) { // Check to ensure the stack is initialized or if theres nothing to remove
        return false;
    }
    *out = s->data[--s->length]; // Decrements lenght then assigns the value stored in the current index being popped to the output variable
    return true; // Return true indicating no errors have occured 
}
