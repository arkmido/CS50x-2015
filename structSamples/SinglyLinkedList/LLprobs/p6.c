/*
    Linked List Problem 6
    
    SortedInsert() : given a list sorted in increasing order
                   : insert a node in the correct position
    
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
     for(int i = 5; i >= 1; i--)
     {
        if(i !=3) Push(&(*head),i);
     }
}

void print(node *head){
    for(; head != NULL; head = head->next)
        printf(" %d", head->data);
    printf("\n");
}

void SortedInsert(node **headRef, node *newNode){
    node *current = *headRef;
    
    if(newNode->data <= (*headRef)->data){
        newNode->next = current;
        *headRef = newNode;
        return;
    }
    
    while(current->next != NULL && current->next->data < newNode->data){
            current = current->next; 
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return;
}

int main(void){
    node *head = NULL;
    
    buildFront(&head);
    
    print(head);
    
    int len = length(head);
    printf("%d\n", len);
    
    node *newNode = createNode(1);
    SortedInsert(&head, newNode);
    
    
    print(head);
    
    len = length(head);
    printf("%d\n", len);
    
}
