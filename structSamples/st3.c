#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct 
{
    char name[50];
    int sNum;
    int cap;
}Student;

typedef struct 
{
    int rmNum;
    Student *std;
}Room;

void print(Room *r, int *rooms);

int main(void)
{
    int rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);
    Room rptr[rooms];
    
    Student *sptr = malloc(sizeof(Student));
    if(sptr == NULL)
    {
        printf("Oops.. something went wrong\n");
        return -1;
    }
        
    for(int i = 0; i < rooms; i++)
    {
        printf("Enter room number: ");
        scanf("%d", &rptr[i].rmNum);
        
        int n;
        printf("Enter number of students in this room: ");
        scanf("%d", &n);
        
        sptr = realloc(sptr, n*sizeof(Student));
       
        for(int j = 0; j < n; j++)
        {
            printf("Enter student name: ");
            scanf("%s", sptr+j->name);
            
            printf("Enter student number: ");
            scanf("%d", &sptr+j.std->sNum);
        }
        
        rptr[i].std = sptr;
        rptr[i].std->cap = n;
    }
    
    print(rptr, &rooms);

}

void print(Room *r, int *rooms)
{
    for(int i = 0; i < *rooms; i++)
    {
        printf("--Room #:%d--\n", r[i].rmNum);
        
        for(int j = 0; j < r[i].std->cap; j++)
            printf("%s,\t%d\n", r[j].std->name, r[j].std->sNum);
    }
}

