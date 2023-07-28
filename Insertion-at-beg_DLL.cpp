#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the DLL
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL)
        (*headRef)->prev = newNode;
    *headRef = newNode;
}

// Function to print the DLL
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int data, n;

    // Take input for the original linked list
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtBeginning(&head, data);
    }

    // Original linked list
    printf("Original linked list: ");
    printList(head);

    // Insertion at the beginning of the DLL
    int newData;
    printf("Enter the data to insert at the beginning: ");
    scanf("%d", &newData);

    printf("DLL after inserting at the beginning: ");
    insertAtBeginning(&head, newData);
    printList(head);

    return 0;
}
