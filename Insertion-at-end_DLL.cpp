#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head_ref, struct Node** tail_ref, int data) {
    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    // If the list is empty, make the new node as the head and tail node
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        *tail_ref = new_node;
        return;
    }

    // Insert the new node at the end
    new_node->prev = *tail_ref;
    (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Initialize an empty doubly linked list
    struct Node* head = NULL;
    struct Node* tail = NULL;

    int numNodes;
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &numNodes);

    // Insert nodes at the end
    for (int i = 0; i < numNodes; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, &tail, data);
    }

    // Print the doubly linked list
    printf("Doubly Linked List: ");
    printList(head);

    return 0;
}
