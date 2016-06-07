/*
    Combined functions to insert nodes
    at the end, beginning and at nth position
    
    now add a function to delete a node at nth position
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
void delnth(Node**, int);
void destroy_list(Node*);

int list_length(Node*);

// MAIN
int main(void)
{
    Node *head = NULL;
    int cont = 0;
    do
    {
        int ch;   
        printf("Where to insert n?\n1 = beginning\n2 = end\n3 = nth position\n4 = delete at nth position\n");
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
            int list = list_length(head);
            
            if(((pos-1) <= list) && pos > 0)
            {
                int val;
                printf("Enter n: ");
                scanf("%d", &val);
                inNth(&head, &val, pos);
            }
            else
            {
                printf("Invalid position\n");
            }
        }
        else if(ch == 4)
        {
            int pos;
            printf("Enter position to delete node: ");
            scanf("%d", &pos);
            
            delnth(&head, pos);
        }
        prntList(head);
        
        printf("Press 1 to continue: ");
        scanf("%d", &cont);
     }
     while(cont == 1);
     
     destroy_list(head);
}
//-------- Function implementations ------------

// list length checking
int list_length(Node *ptr)
{
    int count = 0;
    for(; ptr != NULL; count++)
        ptr = ptr->next;
        
    return count;
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

// Delete node at nth position
void delnth(Node** ptr, int pos)
{
    int list = list_length(*ptr);
    if(list == 0 || pos > list || pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }
    
    Node *temp1 = *ptr;
    if(pos == 1)
    {
        *ptr = temp1->next;
        free(temp1);
        printf("Deleted!\n");
        return;
    }
    int i;
    for(i = 0; i < pos-2; i++)
        temp1 = temp1->next;
    
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    printf("Deleted!\n");

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
