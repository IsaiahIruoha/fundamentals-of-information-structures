#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_node {
    int value;
    struct list_node *next;
} node;

void print_list(node* head) {
    node *temp = head; 
    while (temp != NULL) {
        printf("%d", temp->value); 
        temp = temp->next; 
        if (temp != NULL) {
           printf(", ");  
        }
    }
    printf("\n");
}

node* insertFirst(node* head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->value = data; 
    head = new_node; 
    return head; 
}

void insert_at_tail(node** head, int data) {
    node* new_node = (node*)malloc(sizeof(node)); 
    new_node->next = NULL;
    new_node->value = data; 
    if (*head == NULL) {
        *head = new_node; 
        return; 
    }
    node* temp = *head; 
    while (temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = new_node; 
}

void swap_adjacent(node* head) {
    node* temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        int temp_val = temp->value;
        temp->value = temp->next->value;
        temp->next->value = temp_val;
        temp = temp->next->next;
    }
}

void double_list(node* head) {
    if (head == NULL) {
        return; 
    }

    node* tail = head;

    while (tail->next != NULL) {
        tail = tail->next; 
    }

    node* newHead = NULL;
    node* newCurrent = NULL;

    while (head != NULL) {
        node *newNode = (node*)malloc(sizeof(node));
            newNode->value = head->value;
            newNode->next = NULL;

            if (newHead == NULL) {
                newHead = newNode;
                newCurrent = newNode;
            } else {
                newCurrent->next = newNode;
                newCurrent = newNode;
            }
        head = head->next;
    }
    tail->next = newHead;
}

void remove_adjacent_duplicates(node* head) {
    node* temp = head;
    while(temp != NULL && temp->next != NULL)
    {
        if(temp->value == temp->next->value)
        {
            node* node_to_delete = temp->next;
            temp->next = temp->next->next;
            free(node_to_delete); 
        }
        else
        {
            temp = temp->next;
        }
    }
}

int main() {
    // List is initially empty.
    node* head = NULL;

    // insert head
    head = insertFirst(head, 1);
    insert_at_tail(&head, 2);
    insert_at_tail(&head, 3);
    insert_at_tail(&head, 3);
    insert_at_tail(&head, 3);
    insert_at_tail(&head, 3);
    insert_at_tail(&head, 4);
    insert_at_tail(&head, 5);
    insert_at_tail(&head, 6);

    printf("Original list: ");
    print_list(head);

    printf("\nSwapping adjacent items: ");
    swap_adjacent(head);
    print_list(head);

    printf("\nDuplicating all items: ");
    double_list(head);
    print_list(head);

    printf("\nRemoving adjacent duplicates: ");
    remove_adjacent_duplicates(head);
    print_list(head);

    return 0; 
}