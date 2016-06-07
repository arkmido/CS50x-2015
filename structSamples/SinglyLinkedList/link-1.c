/*
    Introduction to Linked List
    Finding a value from hard-coded nodes
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

void find(struct node *ptr, int val)
{
    while(ptr != 0)
    {
        if(ptr->val == val) 
        {
            printf("FOUND!\n");
            return;
        }
        else ptr = ptr->next;
    }
    printf("Value not found\n");
}

int main(void)
{    
    
    struct node n1,n2,n3;
    n1.val = 1;
    n1.next = &n2;
    
    n2.val = 2;
    n2.next = &n3;
    
    n3.val = 3;
    struct node n4;
    n3.next = &n4;
    
    n4.val = 50;
    n4.next = 0;
    
    struct node *start = &n1;
    
    int num;
    printf("find: ");
    scanf("%d", &num);
    find(start,num);
}
