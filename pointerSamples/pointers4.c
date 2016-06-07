#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int n, m;
    int *p, *q;
    
    p = &n;
    q = &m;
    
    n = 10;
	m = 20;
	
	p = q;
	q = NULL;

	printf("*p is %d\n", *p);
	printf("*q is %d\n", *q);
	printf("n is %d\n", n);
	printf("m is %d\n", m);
}
