/*
    Create a function that allows users
    to insert a node at the end of a linked-list
    
    start with 0 nodes
    
*/

#include <stdio.h>
#include <stdlib.h>

// the struct for each node
typedef struct Node
{
    int val;
    struct Node *next;
}Node;

// free each node
void destroy_list(Node *head)
{
    while(head != NULL)
    {
        Node *temp = head->next;
        free(head);
        head = temp;
    }
}

// printing the list
void print(Node *ptr)
{
    while(ptr != NULL)
    {
        printf(" %d",ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

// inserting algorithm at the end of each node
void insert_end(Node **ptr, int *val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) return;
    
    newNode->val = *val;
    newNode->next = NULL;
    
    if(*ptr != NULL)
    {
        Node *temp = *ptr;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    else
        *ptr = newNode;
}

int main(void)
{
    Node *head = NULL;
    int ctr;
    
    printf("Enter how many elements to insert: ");
    scanf("%d", &ctr);
    
    for(int i = 0; i < ctr; i++)
    {   
        int n;
        printf("Enter n: ");
        scanf("%d", &n);
        
        insert_end(&head, &n);
        print(head);
    }
    
    destroy_list(head);
}
