#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
};

struct entry *findEntry(struct entry *listPtr, int match)
{
    while(listPtr != 0)
    {
        if(listPtr->value == match)
            return listPtr;
        else
            listPtr = listPtr->next;
    }
    
    return  0;
}

int main(void)
{
    struct entry *findEntry(struct entry *listPtr, int match);
    struct entry n1,n2,n3;
    struct entry *listPtr, *listStart = &n1;
    
    int search;
    
    n1.value = 100;
    n1.next = &n2;
    
    n2.value = 200;
    n2.next = &n3;
    
    n3.value = 300;
    n3.next = 0;
    
    printf("Enter value to locate: ");
    scanf("%i", &search);
    
    listPtr = findEntry(listStart, search);
    
    if(listPtr != 0)
        printf("Found %i.\n", listPtr->value);
    else
        printf("Not found.\n");
}
