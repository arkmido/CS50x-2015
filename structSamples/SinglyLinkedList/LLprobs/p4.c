/*
    Linked List Problem 0
    
    Pop()       : takes a non-empty list, deletes head node
                : (not head) and returns head node data
    
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

int Pop(node **headRef){
    assert((*headRef) != NULL);

    int data = (*headRef)->data;
    node *temp = (*headRef);
    (*headRef) = (*headRef)->next;
    free(temp);
    
    return data;
}

int main(void){
    node *head = NULL;
    
    buildFront(&head);
    
    int len = length(head);
    printf("%d\n", len);
    
    for(int i = 0, n = 0; i < 5; i++){
        n = Pop(&head);
        printf("%d\n", n);
    }
    len = length(head);
    printf("%d\n", len);
}
