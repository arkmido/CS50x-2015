/*
    trie-3.c
    Trie implementation using boolean and array
    (singly linked list)
    
    [c] Robert Love: http://ideone.com/gZcfFp
    commented from: geeksforgeeks.org/trie-delete
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 27

struct trie
{
    bool leaf;
    struct trie *children[SIZE];
};

struct trie *newNode()
{
    struct trie *temp = (struct trie *)malloc(sizeof(struct trie));
    temp->leaf = false;
    
    for(int i = 0; i < SIZE; i++)
        temp->children[i] = NULL;
    
    return temp;
}

// insert
void insert(struct trie *root, char key[])
{
    int len = strlen(key);
    for(int i = 0; i < len; i++)
    {
        int index = key[i] == '\'' ? 26 : tolower(key[i]) - 'a';
        if(!root->children[index])
            root->children[index] = newNode();
        
        root = root->children[index];
    }
    
    root->leaf = true;
}

// search
bool search(struct trie *root, char key[])
{
    if(!root)
        return false;
        
    int len = strlen(key);
    for(int i = 0; i < len; i++)
    {
        int index = key[i] == '\'' ? 26 : tolower(key[i]) - 'a';
        if(!root->children[index])
            return false;
        
        root = root->children[index];
    }
    if(!root->leaf)
        return false;
        
    return true;
}

bool isEmpty(struct trie *root)
{
    for(int i = 0; i < SIZE; i++)
        if(root->children[i])
            return false;
        
    return true;
}

// remove
struct trie *removeKey(struct trie *root, char key[], int depth)
{
    if(!root) return NULL;
    
    if(depth == strlen(key))
    {
        if(root->leaf) root->leaf = false;
        if(isEmpty(root))
        {
            free(root);
            root = NULL;
        }
        return root;
    }
    
    int index = key[depth] == '\'' ? 26 : tolower(key[depth]) - 'a';
    root->children[index] = removeKey(root->children[index], key, depth+1);
    
    if(isEmpty(root) && !root->leaf)
    {
        free(root);
        root = NULL;
    }
    return root;
}

void freeNode(struct trie *root)
{
    if(!root) return;
    
    for(int i = 0; i < SIZE; i++)
    {
        if(root->children[i] != NULL)
        {
            freeNode(root->children[i]);
        }
    }
    free(root);
    root = NULL;
}

int main(void)
{
    struct trie *root = newNode();
    
    FILE *f = fopen("text.txt", "rt");
    if(f == NULL)
        return -1;
    //int c = 0;
    //int i = 0;
    char buffer[20];
    
    while(fgets(buffer,20,f) != NULL)
    {
        size_t len = strlen(buffer);
        if(len > 45)
        if(len > 0 && buffer[len-1] == '\n')
            buffer[--len] = '\0';
            
        insert(root, buffer);
    }
    
    /*    while(1)*/
/*    {*/
/*        c = fgetc(f);*/
/*        if(c == EOF)*/
/*            break;*/
/*        if(c == '\n')*/
/*        {*/
/*            insert(head, word);*/
/*            numOfWords++;*/
/*            i = 0;*/
/*            for(unsigned int j = 0; j < LENGTH; j++)*/
/*                word[j] = '\0';*/
/*        }*/
/*        else*/
/*        {*/
/*            word[i] = (char)c;*/
/*            i++;*/
/*        }*/
/*    }*/

    fclose(f);
    
    if(search(root, "aa")) printf("true\n");
    else printf("false\n");
    if(search(root, "a's")) printf("true\n");
    else printf("false\n");
    if(search(root, "bb")) printf("true\n");
    else printf("false\n");
    
    
    freeNode(root);
}
