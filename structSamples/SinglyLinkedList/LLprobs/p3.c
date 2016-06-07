/*
    Linked List Problem 0
    
    DeleteList() : free all heap allocation
                 : and reset head to NULL
    
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

void DeleteList(node **head){
    while((*head) != NULL){
        node *temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    }
    (*head) = NULL;
}

int main(void){
    node *head = NULL;
    
    buildFront(&head);
    
    int len = length(head);
    printf("%d\n", len);
    
    DeleteList(&head);
    
    len = length(head);
    printf("%d\n", len);
}
