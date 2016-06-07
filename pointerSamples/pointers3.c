#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);

int main(void){
    /*
    int *p = malloc(sizeof(int));
    if(p == NULL){
        printf("ERROR OCCURED\n");
        return -1;
    }
    scanf("%d", p);
    printf("p = %d\n", *p);
    free(p);
    */
    
    int x = 45;
    int y = 5;
    
    swap(&x, &y);
    
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    
}
void swap(int *x, int *y){
    int a = *x;
    *x = *y;
    *y = a;
}
