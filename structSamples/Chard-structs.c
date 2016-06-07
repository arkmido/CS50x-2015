#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);
    
    who->name = name;
    who->age = age;
    who->height = height;
    who->weight = weight;
    
    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);
    
    //free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(void)
{
    // make two people structs
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 120);
    
    printf("Joe is at %p memory location\n", joe);
    Person_print(joe);
    
    printf("Frank is at %p memory location\n", frank);
    Person_print(frank);
    
    Person_destroy(joe);
    Person_destroy(frank);
}
