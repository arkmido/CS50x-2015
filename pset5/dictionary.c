/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 * [c] to the author from ideone.com/gZcfFp
 ***************************************************************************/


#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"

#define SIZE 27

typedef struct trieNode
{
    bool isWord;
    struct trieNode *child[SIZE];
}trieNode;

trieNode *head = NULL;
unsigned int numOfWords = 0;

// ---------------- HELPER FUNCTIONS ------------------
trieNode *newNode()
{
    trieNode *temp = (trieNode *)malloc(sizeof(trieNode));
    temp->isWord = false;
    
    for(unsigned int i = 0; i < SIZE; i++)
        temp->child[i] = NULL;
    return temp;
}

void insert(trieNode *root, char key[])
{
    for(unsigned int i = 0, len = strlen(key); i < len; i++)
    {
        unsigned int index = key[i] == '\'' ? 26 : tolower(key[i]) - 'a';
        if(!root->child[index])
            root->child[index] = newNode();
        
        root = root->child[index];
    }
    
    root->isWord = true;
}
void freeNode(trieNode *root)
{
    if(!root) return;
    
    for(unsigned int i = 0; i < SIZE; i++)
        if(root->child[i] != NULL)
            freeNode(root->child[i]);
            
    free(root);
    root = NULL;
}
// ----------------------------------------------
 

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    trieNode *root = head;
    
    if(!root) return false;
        
    unsigned int len = strlen(word);
    for(unsigned int i = 0; i < len; i++)
    {
        unsigned int index = word[i] == '\'' ? 26 : tolower(word[i]) - 'a';
        if(!root->child[index])
            return false;
            
        root = root->child[index];
    }
    if(!root->isWord)
        return false;
    
    return true;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    head = newNode();

    FILE *f = fopen(dictionary, "r");
    if(f == NULL)
    {
        printf("Failed to open dictionary\n");
        return false;
    }
    
    char word[50];
    
    while(fgets(word,50,f) != NULL)
    {
        size_t len = strlen(word);
        if(len > 0 && word[len-1] == '\n')
            word[len-1] = '\0';
                
        insert(head, word);
        numOfWords++;
    }
    fclose(f);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return numOfWords;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    freeNode(head);
    return true;
}

