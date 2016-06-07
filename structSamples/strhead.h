#include <cs50.h>

typedef struct
{
    string name;
    int number;
}Room;

typedef struct
{
    string name;
    string address;
    Room *room;
}House;

typedef struct
{
    char name[50];
    string house;
}Student;
