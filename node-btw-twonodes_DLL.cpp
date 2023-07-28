#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node between two nodes in the doubly linked list
void insertBetween(struct Node* prev_node, struct Node* next_node, int data) {
    if (prev_node == NULL || next_node == NULL) {
        printf("Invalid input! Cannot insert node.\n");
        return;
    }

    struct Node* new_node = createNode(data);
    new_node->prev = prev_node;
    new_node->next = next_node;
    prev_node->next = new_node;
    next_node->prev = new_node;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = createNode(1);
    struct Node* second_node = createNode(2);
    struct Node* tail = createNode(3);

    // Link the nodes
    head->next = second_node;
    second_node->prev = head;
    second_node->next = tail;
    tail->prev = second_node;

    printf("Original Doubly Linked List: ");
    printList(head);

    int data_to_insert = 4;
    printf("Enter the data to insert between two nodes: ");
    scanf("%d", &data_to_insert);

    insertBetween(head, second_node, data_to_insert);

    printf("Modified Doubly Linked List: ");
    printList(head);

    // Free memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
    