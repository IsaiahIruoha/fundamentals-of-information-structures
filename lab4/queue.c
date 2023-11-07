#include "queue.h" // Include the queue header file
#include <string.h>

#define DEFAULT_CAPACITY 8 // Define the default capacity for the queue (arbitrary value)

void init_queue(struct queue *q)
{
    q->data = NULL;  // Initialize data to NULL
    q->capacity = 0; // Initialize capacity to 0
    q->offset = 0;   // Initialize offset to 0
    q->length = 0;   // Initialize length to 0
}

void clear_queue(struct queue *q)
{
    if (q->data != NULL) // If not null
    {                  
        free(q->data); // Free memory
        init_queue(q); // Reset the queue to initial state
    }
}

void enqueue(struct queue *q, int value) // Add a value to the queue
{ 
    if (q->length == q->capacity) // Check if the queue is full
    {
        if (q->capacity > 0)
        {
            q->capacity *= 2; // Double the capacity if necessary
            q->data = realloc(q->data, sizeof(int) * q->capacity);
            // Move elements to make space for new values
            memmove(q->data + q->length + q->offset, q->data + q->offset, sizeof(int) * (q->length - q->offset));
        }
        else
        {
            q->data = malloc(sizeof(int) * DEFAULT_CAPACITY); // Allocate memory with default capacity
            q->capacity = DEFAULT_CAPACITY;
        }
    }
    q->data[(q->offset + q->length++) % q->capacity] = value; // Add a new value to the queue
}

bool dequeue(struct queue *q, int *out)
{
    if (q->length == 0)
        return false;          // If the queue is empty, return false
    *out = q->data[q->offset]; // Get the value at the front of the queue
    if (++q->offset == q->capacity)
        q->offset = 0; // Reset the offset if it reaches the end
    q->length--;       // Reduce the length of the queue
    return true;       // Return true to indicate a successful dequeue
}

bool queue_empty(struct queue *q)
{
    return (q->length == 0); // Check if the queue is empty and return a boolean result
}