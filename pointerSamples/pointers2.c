#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n = 40;
    int *p = malloc(sizeof(int));
    printf("p is %d\n", (int)p);
    
    p = &n;
    
    printf("p is %d\n", (int)p);
    printf("n is %d\n", (int)&n);
    printf("%d\n", *p);
    
    free(p);
}
