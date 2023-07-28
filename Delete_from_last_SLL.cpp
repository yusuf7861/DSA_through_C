#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void deleteLastNode(struct Node** head)
{
    if(*head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    if((*head)->next == NULL)
    {
        // if there is only one node, delete it and set head to NULL
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    
    // traverse the list until the last node is reached
    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    
    // updates the previous node's next pointer to NULL to remove the last node
    prev->next = NULL;
    free(current);
    printf("Last Node deleted from the linked list.\n");
    
}

int main()
{
    struct Node* head = NULL;
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    
    head = node1;
    node1->data = 1;
    node1->next = node2;
    node2->data = 2;
    node2->next = node3;
    node3->data = 3;
    node3->next = NULL;
    // YOU CAN ADD MORE ELEMENT AS YOU WISH
    
    printf("Linked List before deletion: ");
    struct Node* current = head;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    
    deleteLastNode(&head);
    printf("Linked List after deletion: ");
    if(head != NULL)
    {
        current = head;
        while(current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
    }
    printf("\n");
    
    //free the memory allocated for the node
    struct Node* temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}