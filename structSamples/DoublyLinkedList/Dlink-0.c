/*
    Using logics used in Singly Linked List
    create a Doubly Linked List with a function
    to insert a node at the head
    
    start with 0 nodes
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Node structures
typedef struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;
}Node;

//----FUNCTION prototypes-----
void inHead(int val);
Node *new(int val);
void printList(void);

// ---------- MAIN ----------
// global head pointer
Node *head = NULL;
int main(void)
{
    int n;
    printf("Enter # of elements: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        int val;
        printf("Enter n: ");
        scanf("%d", &val);
        inHead(val);
    }
    printList();
}

// ------------ FUNCTION IMPLEMENTATIONS ---------------

// insert node at beginning
void inHead(int val)
{
    Node *newNode = new(val);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// print list values
void printList(void)
{
    while(head != NULL)
    {
        printf(" %d", head->val);
        head = head->next;
    }
    printf("\n");
}

// function to create a new node
Node *new(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    assert(newNode != NULL);
    
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}
