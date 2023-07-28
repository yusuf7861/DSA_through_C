#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create and insert a new node at the end of the doubly linked list
void insertAtEnd(struct Node** head_ref, struct Node** tail_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        *tail_ref = new_node;
        return;
    }

    new_node->prev = *tail_ref;
    (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

// Function to insert a new node between two nodes in the doubly linked list
void insertBetween(struct Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("Previous node cannot be NULL!\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }
    prev_node->next = new_node;
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
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int numNodes, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, &tail, data);
    }

    if (numNodes >= 2) {
        printf("Enter the data to insert between two nodes: ");
        scanf("%d", &data);

        // Assuming we want to insert between the second and third node (index 1 and index 2)
        struct Node* second_node = head->next;
        insertBetween(second_node, data);
    } else if (numNodes == 1) {
        printf("Only one node in the list. Enter data for the second node: ");
        scanf("%d", &data);
        insertAtEnd(&head, &tail, data);
    }

    printf("Doubly Linked List: ");
    printList(head);

    return 0;
}
