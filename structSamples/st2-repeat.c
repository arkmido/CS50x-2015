#include <stdio.h>
#include <stdlib.h>

struct Name
{
    int num;
    char str[50];
};

int main(void)
{   
    struct Name *sptr;
    int n;
    
    printf("Enter n: ");
    scanf("%d", &n);
    
    sptr = malloc(n*sizeof(struct Name));
    
    if(sptr == NULL)
        return -1;
    
    for(int i = 0; i < n; i++)
    {
        printf("Enter String and Number respectively: ");
        scanf("%s%d", (sptr+i)->str, &(sptr+i)->num);
    }
    
     for(int j=0; j < n; j++)
        printf("%s\t%d\n", (sptr+j)->str, (sptr+j)->num);
    
    free(sptr);
}
