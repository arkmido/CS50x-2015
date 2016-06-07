/*
    Create a function that allows a user to
    insert a node at the beginning of a linked list
    
    start the list at 0 nodes
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
}Node;

void printList(Node *ptr)
{
    while(ptr != NULL)
    {
        printf(" %d",ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

Node *insert_begin(Node *head, int *n)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory error\n");
        return NULL;
    }
    
    newNode->value = *n;
    newNode->next = head;
    
    return newNode;
}

void destroy_list(Node *head)
{
    while(head != NULL)
    {
        Node *temp = head->next;
        free(head);
        head = temp;
    }
}

int main(void)
{
    Node *head = NULL;
    int elem, n;
    
    printf("Enter how many elements: ");
    scanf("%d", &elem);
    
    for(int i = 0; i < elem; i++)
    {
        printf("Enter n%d: ", i+1);
        scanf("%d", &n);
        head = insert_begin(head, &n);
        printList(head);
    }
    destroy_list(head);
}
