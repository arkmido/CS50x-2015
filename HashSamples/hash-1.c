/*
    Hash Tables
    Implementation using Separate Chaining
    [c] - youtube/Paul Programming
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define TABLE_SIZE 5

// structure to hold values in buckets
typedef struct chain{
    char *name;
    char *drink;
    struct chain *link;
}chain;

// hash table that points to chains
chain *HashTable[TABLE_SIZE];

// initialize all indices in the hashTable
void init_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        HashTable[i] = malloc(sizeof(chain));
        // define the size for name and drink
        HashTable[i]->name = malloc(sizeof("empty"));
        HashTable[i]->drink = malloc(sizeof("empty"));
        assert(HashTable[i]->name != NULL && HashTable[i]->drink != NULL);
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->link = NULL;
    }
}

// ----- The Hash Function -----
int hash(char *key){
    unsigned int hash = 0;
    unsigned int index = strlen(key);
    
    for(int i = 0; i < index; i++){
        hash += (int)key[i] + 37;   
        //printf("hash = %d\n", hash);
    }
    
    return index = hash%TABLE_SIZE;
}

// adding chains to the buckets and linking
// add item to bucket list :)
void AddItem(char *name, char *drink){
    unsigned int index = hash(name);
    
    if(strcmp(HashTable[index]->name, "empty") == 0){
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }else{
        chain *newPtr = (chain *)malloc(sizeof(chain));
        assert(newPtr != NULL);
        newPtr->name = name;
        newPtr->drink = drink;
        newPtr->link = HashTable[index]; 
        HashTable[index] = newPtr;
    }
}

// returns length of chains in a bucket(index)
int chain_length(unsigned int index){
    unsigned int count = 0;
    if(strcmp(HashTable[index]->name, "empty") == 0)
        return count;
    
    chain *ptr = HashTable[index];
    count++;
    while(ptr->link != NULL){
        count++;
        ptr = ptr->link;
    }
    return count;
}

// print hashtable buckets, # of items, and first item
void printTable(){
    unsigned int number;
    for(int i = 0; i < TABLE_SIZE; i++){
        number = chain_length(i);
        printf("======================\n"); 
        printf("index: %d\n",i);
        printf("%s\n", HashTable[i]->name);
        printf("%s\n", HashTable[i]->drink);
        printf("# of item/s: %d\n", number);
    }
    printf("======================\n");
}

// print chains inside a bucket
void printChain(unsigned int index){
    chain *ptr = HashTable[index];
    if(strcmp(ptr->name, "empty") == 0){
        printf("index: %d is empty\n",index);
        return;
    }
    printf("-------------\n");
    printf("index: %d contains..\n", index);
    while(ptr != NULL){
        printf("%s\n",ptr->name);
        printf("%s\n",ptr->drink);
        printf("-------------\n");
        ptr = ptr->link;
    }
}

// finds if a chain exist in the hashTable
// hash the name and gets the drink... yeah
void findDrink(char *name){
    unsigned int index = hash(name);
    bool found = false;
    char *drink;
    
    chain *ptr = HashTable[index];
    while(ptr != NULL){
        if(strcmp(ptr->name, name) == 0){
            found = true;
            drink = ptr->drink;
        }
        ptr = ptr->link;
    }
    if(found)
        printf("Favorite drink: %s\n",drink);
    else
        printf("%s not found in the table\n",name);
}

// removing a chain in the bucket
void RemoveItem(char *name){
    unsigned int index = hash(name);
    chain *delPtr;
    chain *ptr1;
    chain *ptr2;
    
    // case 0: bucket is empty or "empty"
    if(strcmp(HashTable[index]->name, "empty")==0){
        printf("%s is not in the hash table\n", name);
    }    
    // case 1: bucket has only one chain
    else if(strcmp(HashTable[index]->name,name)==0 && HashTable[index]->link == NULL){
        HashTable[index]->name = "empty";
        HashTable[index]->drink = "empty";
        
        printf("%s is removed\n",name);
    }
    // case 2: name is the first chain and there
    //         other leading chains
    else if(strcmp(HashTable[index]->name,name)==0){
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index]->link;
        free(delPtr);
        printf("%s is removed\n",name);
    }
    // case 3: name is not the first chain
    //         and there are other chains
    else{
        ptr1 = HashTable[index]->link;
        ptr2 = HashTable[index];

        while(ptr1 != NULL && strcmp(ptr1->name,name)==0){
            ptr2 = ptr1;
            ptr1 = ptr1->link;
        }
        // case 3.1: no match
        if(ptr1 == NULL)
             printf("%s is not in the hash table\n", name);
            
        // case 3.2: match is somewhere in the links
        else{
            delPtr = ptr1;
            ptr1 = ptr1->link;
            ptr2->link = ptr1;
            free(delPtr);
            printf("%s is removed\n",name);
        }
    }
}

// MAIN
int main(void){
    init_table();
    
    AddItem("Paula", "coffee");
    AddItem("Puala", "tea");
    AddItem("Pulaa", "water");
    AddItem("Balbasor", "greentea");
    AddItem("Paul", "Locha");
    AddItem("Anne", "Hot Chocolate");
    AddItem("Bill", "Root Beer");
    AddItem("Joe", "Skinny Latte");
        
    printTable();
    RemoveItem("Joe");
    printTable();
    RemoveItem("Balbasor");
    printTable();
    RemoveItem("Joe");
    printChain(2);
    
/*    char name[10];

    while(!(strcmp(name,"exit")==0)){
        printf("Search for: ");
        scanf("%s", name);
        if(strcmp(name, "exit")!=0)
            findDrink(name);
        printf("\n");
    }*/
    
}

