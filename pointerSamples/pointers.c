#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *x = malloc(sizeof(int));
    int *y = malloc(sizeof(int));
    
    *x = 1;
    *y = 2;
    
    printf("*x is %d\n", *x);
    printf("*y is %d\n", *y);
    
    // free(x);
    
    // x = y;
    
    printf("x now points to y\n");
    printf("*x is %d\n", *x);
    printf("*y is %d\n", *y);
    
    free(x);
    
}
