/*
    Linked List Problem 0
    
    length()     : returns the length of list
    Push()       : insert node at the head
    buildFront() : build list using Push()
    createNode() : creates a node and returns the pointer
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *createNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    assert(newNode != NULL);
    
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

int length(node *head){
    int count = 0;
    for(; head != NULL; head = head->next, count++);  
    return count;
}

void Push(node **headRef, int data){
    node *newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void buildFront(node **head){
     for(int i = 1; i <= 5; i++)
        Push(&(*head),i);
}

void print(node *head){
    for(; head != NULL; head = head->next)
        printf(" %d", head->val);
    printf("\n");
}

int main(void){
    node *head = NULL;
    
    buildFront(&head);
    
    int len = length(head);
    printf("%d\n", len);
}
