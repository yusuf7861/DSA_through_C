#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
 // function to delete a node from the beginning
void deleteFromBeginning(struct Node** head)
{
    if(*head == NULL)
    {
        printf("Linked List a empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    // (*head) explicitly dereferences the pointer 'head' to access it's value
    free(temp);
    printf("Node deleted from the beginning");
}

void displayLinkedList(struct Node* head)
{
    if(head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    struct Node *current = head;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next; // traversing the full list one by one
        
    }
    printf("\n");    
}

// function to create new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    struct Node* head  = NULL;
    struct Node* Node1 = createNode(1);
    struct Node* Node2 = createNode(2);
    struct Node* Node3 = createNode(3);
    
    //building the linked list
    head = Node1;
    Node1->next = Node2;
    Node2->next = Node3;
    
    printf("Linked List before deletion: ");
    displayLinkedList(head);
    
    deleteFromBeginning(&head);
    
    
    printf("Linked List after deletion: ");
    displayLinkedList(head);
    
    return 0;
}