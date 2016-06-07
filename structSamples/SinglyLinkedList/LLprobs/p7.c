/*
    Linked List Problem 7
    
    InsertSort() : using sortedInsert(), arrange a given list's
                 : nodes in increasing order
                 
                 : Implemented function does not build a new list
                 : but arrange the existing list using iteration
                 : and comparison.
    
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
     for(int i = 2; i <= 8; i+=2)
     {
        Push(&(*head),i);
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

void InsertSort(node **head){
    node *current = *head;
    node *ptr = (*head)->next;
    
    while(ptr != NULL){
        current = *head;
        *head = (*head)->next;
        SortedInsert(&(*head), current);
        ptr = ptr->next;
    }
}

int main(void){
    node *head = NULL;  
    buildFront(&head);
    
    print(head);
    
    InsertSort(&head);
    
    print(head);
    
}
