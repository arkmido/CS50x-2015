/*
    Combine functions to add nodes at the beginning
    and at the end of a linked-list
    
    then add another function to add a node
    at nth position in the list
    
    start with 0 nodes
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Struct
typedef struct Node
{
    int val;
    struct Node *next;
}Node;

// Function Prototypes
void prntList(Node*);
void inBegin(Node**, int*);
void inEnd(Node**, int*);
void inNth(Node**, int*, int);
void destroy_list(Node*);
int check_list(Node*, int);

// MAIN
int main(void)
{
    Node *head = NULL;
    int cont = 0;
    do
    {
        int ch;   
        printf("Where to insert n?\n1 = beginning\n2 = end\n3 = nth position\n");
        scanf("%d", &ch);
        
        if(ch == 1)
        {
            int n;
            printf("Enter # of elements: ");
            scanf("%d", &n);
            
            printf("Inserting at the beginning\n");
            for(int i = 0; i < n; i++)
            {
                int val;
                printf("Enter n: ");
                scanf("%d", &val); 
                inBegin(&head, &val);        
            }
        }
        else if(ch == 2)
        {
            int n;
            printf("Enter # of elements: ");
            scanf("%d", &n);
            
            printf("Inserting at the end\n");
            for(int i = 0; i < n; i++)
            {
                int val;
                printf("Enter n: ");
                scanf("%d", &val);
                inEnd(&head, &val);
            }
        }
        else if(ch == 3)
        {   
            int pos;
            printf("Enter position to insert node: ");
            scanf("%d", &pos);

            if(check_list(head, pos) > 0)
            {
                int val;
                printf("Enter n: ");
                scanf("%d", &val);
                inNth(&head, &val, pos);
            }
        }
        prntList(head);
        
        printf("Press 1 to continue: ");
        scanf("%d", &cont);
     }
     while(cont == 1);
     
     destroy_list(head);
}
//-------- Function implementations ------------

// checking list
int check_list(Node *ptr, int pos)
{
    // checking if the head pointer is null meaning the list is empty
    // if list is empty, available position only is 1
    if(ptr == NULL && pos != 1)
    {
        printf("List is empty, Invalid position\n");
        return 0;
    }
    
    // checks if the final value of i
    // will be equal to pos after # of iteration through list
    int i;
    for(i = 1; ptr != NULL; i++)
        ptr = ptr->next;
    
    // checking value of i and making sure pos is not less than or equal to 0    
    if((i < pos) || (pos <= 0))
    {    
        printf("Invalid position\n");
        return 0;
    }
        
    return 1;
}


// insert at nth position
void inNth(Node **ptr, int *val, int pos)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    assert(newNode != NULL);
    
    newNode->val = *val;
    newNode->next = NULL;
    
    if(pos == 1)
    {
        newNode->next = *ptr;
        *ptr = newNode;
        return;
    }
    // iteration through the list until pos-1-1
    Node *temp = *ptr;
    for(int i = 0; i < (pos-1)-1; i++)
        temp = temp->next;
        
    newNode->next = temp->next;
    temp->next = newNode;
}

// insert end
void inEnd(Node **ptr, int *val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    assert(newNode != NULL);
    
    newNode->val = *val;
    newNode->next = NULL;
    
    if(*ptr != NULL)
    {
        Node *temp = *ptr;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    else *ptr = newNode;
}

// insert beginning
void inBegin(Node **ptr, int *val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    assert(newNode != NULL);
    
    newNode->val = *val;
    newNode->next = *ptr;
    *ptr = newNode;  
}

// destroy list
void destroy_list(Node *ptr)
{
    while(ptr != NULL)
    {
        Node *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}

// print list
void prntList(Node *ptr)
{
    printf("LIST: ");
    for(; ptr != NULL; ptr = ptr->next)
        printf(" %d", ptr->val);
    printf("\n"); 
}
