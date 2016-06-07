#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char c[50];
}Name;

int main(void)
{
    Name *ptr;
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    
    // allocates memory for n structures w/ ptr pointing to the base address
    ptr = (Name*)malloc(n*sizeof(Name));
    
    if(ptr == NULL)
        return -1;
        
        
    for(int i = 0; i < n; ++i)
    {
        printf("Enter string and integer: ");
        scanf("%s%d", (ptr+i)->c, &(ptr+i)->a);
    }
    
    printf("Displaying information\n");
    for(int i = 0; i < n; ++i)
        printf("%s\t%d\t\n", (ptr+i)->c, (ptr+i)->a);
}
