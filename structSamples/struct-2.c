#include <stdio.h>
#include <stdlib.h>
#include "strhead.h"

#define MAX 2

int main(void)
{
    Student stud[MAX];
    for(int i = 0; i < MAX; i++)
    {
        printf("Student's name: ");
        stud[i].studname = GetString();
        
        printf("Student's house: ");
        stud[i].house = GetString();
    }
    
    FILE *fptr = fopen("students.csv", "w");
    if (fptr != NULL)
    {
        for(int i = 0; i < MAX; i++)
        {
            fprintf(fptr, "%s, %s\n", stud[i].studname, stud[i].house);
        }
        fclose(fptr);
    }
    
    for(int i = 0; i < MAX; i++)
    {
        printf("%s is in %s.\n", stud[i].studname, stud[i].house);
        free(stud[i].studname);
        free(stud[i].house);
    }
      
}
