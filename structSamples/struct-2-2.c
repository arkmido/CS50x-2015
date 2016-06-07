#include <stdio.h>
#include "strhead.h"

int main(void)
{
    Student s1;
    printf("Enter name: ");
    scanf("%s", s1.name);
    printf("Enter house: ");
    s1.house = GetString();
   
    printf("\nName: %s\n", s1.name);
    printf("House: %s\n", s1.house);
}
