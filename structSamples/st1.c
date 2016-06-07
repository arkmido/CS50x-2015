#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[50];
    int roll;
    float marks;
};

int main(void)
{
    struct student s1;
    printf("Enter information of students\n");
    
    printf("Enter name: ");
    scanf("%s", s1.name);
    
    printf("Enter roll number number: ");
    scanf("%d", &s1.roll);
    
    printf("Enter marks: ");
    scanf("%f", &s1.marks);
    
    printf("\nDisplaying Information\n");
    printf("Name: %s\n", s1.name);
    printf("Roll#: %d\n", s1.roll);
    printf("Marks: %.2f\n", s1.marks);
    
}
