/*
    Understanding Function pointers
    with using a simple sort and a callback to comparison function
*/


#include <stdio.h>

int compare(int a, int b, int *c)
{
    /*
    if((a > b) && (*c == 1)) return 1;
    else if((a < b) && (*c == 2)) return 1;
    else return -1;
    */
    if(*c == 1) return a-b;
    else return b-a;
}
//  Main uses of function pointers is to be able to use them as
//  an argument to a function that then returns a callback..
void Bsort(int *a, int size, int *flag, int (*p)(int,int,int*) )
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size-1; j++)
            if(p(a[j],a[j+1],flag) > 0)
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}
// Other uses of function pointers is to be able to store them
// in arrays that allows creation of function tables.
int main(void)
{
    int flag; int A[] = {3,2,1,5,6,4};
    printf("1 = increasing order, 2 = decreasing order\n");
    scanf("%d", &flag);
    if(flag != 1 && flag != 2)
    {
        printf("USAGE: 1 or 2 for sort orders\n");
        return 0;
    }
    Bsort(A,6,&flag,compare);
    
    for(int i = 0; i < 6; i++) printf("%d ",A[i]);
    printf("\n");
}
//-----------------------------------------
/*
void A()
{
    printf("Hello\n");
}

void B(void (*p)())
{
    p();
}

int main(void)
{
    B(A);
}
*/
//-----------------------------------------
/*
void pHello(char *str)
{
    printf("Hello %s\n", str);
}
int Add(int a, int b)
{
    return a+b;
}

int main(void)
{
    void (*p)() = pHello;
    p("Kulangot");
}
*/
