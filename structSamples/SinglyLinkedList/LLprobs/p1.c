/*
    Linked List Problem 1
    
    Write a Count() function that counts the number 
    of times a given int occurs in a list. 
    
    The code for this has the classic list 
    traversal structure as demonstrated in Length().
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

//---------------------------
int countTest(node *head, int data){
    int count = 0;
    for(; head != NULL; head = head->next)
        if(head->data == data)
            count++;
        
    return count;       
}

int main(void){
    node *head = NULL;
    
    buildFront(&head);
    Push(&head,2);
    Push(&head,2);
    Push(&head,3);
    Push(&head,3);
    Push(&head,3);
    
    int occ = countTest(head,2);
    printf("%d\n", occ);
}
