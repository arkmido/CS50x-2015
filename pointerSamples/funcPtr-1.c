/*
    Basic implementation
    and understanding Function pointers
*/

#include <stdio.h>

void A()
{
    printf("Hello\n");
}

void B(void A())
{
    A();
}
void C(void (*A)())
{
    A();
}
int main(void)
{
    B(A);
    C(A);
}
