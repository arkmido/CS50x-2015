/*
    Linked List Problem 0
    
    GetNth()    : takes a linked list & an integer index
                : and returns the value stored at the index
    
    length()     : returns the length of list
    Push()       : insert node at the head
    buildFront() : build list using Push()
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    int data;
    struct node *next;
}node;

int length(node *head){
    int count = 0;
    for(; head != NULL; head = head->next, count++);  
    return count;
}

void Push(node **headRef, int data){
    node *newNode = malloc(sizeof(node));
    assert(newNode != NULL);
    
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

void buildFront(node **head){
     for(int i = 1; i <= 5; i++)
        Push(&(*head),i);
}

int GetNth(node **head, int index){
    assert(index < length(*head) && index >= 0);
    int val = 0;
    for(int i = 0; i <= index; (*head) = (*head)->next, i++)
        val = (*head)->data;
        
    return val;
}

int main(void){
    node *head = NULL;
    
    buildFront(&head);
    
    int len = length(head);
    printf("%d\n", len);
    
    int x = GetNth(&head, 0);
    printf("%d\n", x);
}
