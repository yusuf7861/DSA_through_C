#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void insert(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to reverse the linked list iteratively
void reverseList(struct Node** headRef) {
    struct Node* prevNode = NULL;
    struct Node* currentNode = *headRef;
    struct Node* nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    *headRef = prevNode;
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printf("Original linked list: ");
    printList(head);

    // Reverse the linked list
    reverseList(&head);

    printf("Reversed linked list: ");
    printList(head);

    return 0;
}
