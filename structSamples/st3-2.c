#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct
{
    int room;
    char *name;
    int sNum;
}Student;

Student *create_student(int room, char *name, int sNum)
{
    Student *s = malloc(sizeof(Student));
    assert(s != NULL);
    
    s->room = room;
    s->name = name;
    s->sNum = sNum;
    
    return s;
}

void print_student(Student *s)
{
    printf("Room No.:\t%d\n", s->room);
    printf("Name:\t\t%s\n", s->name);
    printf("Student No.:\t%d\n", s->sNum);
}

int main(void)
{
    Student *s1 = create_student(101, "Student1", 15500);
    print_student(s1);
    
    free(s1);
}
