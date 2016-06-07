/*
    youtube.com/BlueberryTreeTutor
    open addressing hash tables (linear probing)
    
    -- Double Hashing --
    h(k,i) = ( h1(k,i) + i * h2(k,i) ) % m
    
    where: m is a power of 2, h2(k,i) - returns odd value
    
    h1 = a hash function
    h2 = another hash function
    m = size of the array
    i = number of probes starting at 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TAB 512 // <--- m = power of 2

// structure that represents each record
typedef struct{
    char *key;
}hashrec;

// The actual h1 hash function
unsigned int h1(char *k){
    unsigned int h;
    unsigned char *c;
    
    h = 0;
    // loop until dereferencing c yields NULL
    for (c = (unsigned char *)k; *c; c++)
        h = h*37 + *c;
    
    return h;
}

// The actual h2 hash function
unsigned int h2(char *k){
    unsigned int h;
    unsigned char *c;
    
    h = 0;
    // loop until dereferencing c yields NULL
    for (c = (unsigned char *)k; *c; c++)
        h = h*37 + *c;
    
    // m and h2 must be co-primes
    // if h2 is even then add 1;
    return h % 2 == 0 ? h+1 : h;
}

// This is the actual hash function using
// double hashing formula
unsigned int hash(char *k, int i){
    return (h1(k) + i * h2(k)) % HASH_TAB;
}

// return the index of the bucket associated with the key
unsigned int locate(hashrec hashtab[], char *k){
    unsigned int i, b;
    
    for(i = 0; i < HASH_TAB; i++){
        b = hash(k,i);
        if(NULL == hashtab[b].key || 
            strcmp(hashtab[b].key, k) == 0)
            break;
    }
    return b;
}

int member(hashrec hashtab[], char *k){
    unsigned int b = locate(hashtab,k);
    
    if(NULL == hashtab[b].key)
        return 0;
    else
        return strcmp(hashtab[b].key, k) == 0;
}

char *cpy(char *s){
    char *dest, *d;
    d = dest = malloc(strlen(s) * sizeof(char) + 1);
    
    if(d){
        while((*d++ = *s++)){}
    }    
    return dest;
}

int insert(hashrec hashtab[], char *k){
    unsigned int b = locate(hashtab, k);
    
    if(NULL == hashtab[b].key){
        hashtab[b].key = cpy(k);
        return 1;
    }else
        return strcmp(hashtab[b].key, k) == 0;
}

void init_hash_table(hashrec hashtab[]){
    unsigned int b;
    
    for(b = 0; b < HASH_TAB; b++)
        hashtab[b].key = NULL;
}
int main(void){
    char *strings[] = {
        "grape",
        "cherry",
        "orange",
        "grape",
        "apple"
    };
    hashrec hashtab[HASH_TAB];
    size_t i;
    size_t n = sizeof(strings)/sizeof(char*);
    
    init_hash_table(hashtab);
    for(i = 0; i < n; i++)
        if(!member(hashtab, strings[i]))
            insert(hashtab, strings[i]);
        else{
            printf("Duplicate: %s", strings[i]);
            break;
        }
}
