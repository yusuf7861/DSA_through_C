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
    if (node == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", node->data);
    printList(node->next);
}

// Function to reverse the linked list recursively
struct Node* reverseList(struct Node* currentNode, struct Node* prevNode) {
    if (currentNode == NULL)
        return prevNode;

    struct Node* nextNode = currentNode->next;
    currentNode->next = prevNode;
    return reverseList(nextNode, currentNode);
}

// Main function
int main() {
    struct Node* head = NULL;
    int data, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Original linked list: ");
    printList(head);

    // Reverse the linked list
    head = reverseList(head, NULL);

    printf("Reversed linked list: ");
    printList(head);

    return 0;
}
