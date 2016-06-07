/*
    trie-2.c Implementation using Singly Linked List
    
    [c] www.cs.bu.edu/teaching/c/tree/trie
*/

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

// Structure of every nodes in the trie tree
typedef struct node
{
    char key;
    int value;
    // links for the next level and children
    struct node *next, *children;
}node;

// prototype for TrieAdd duplicate validations
node *TrieIsMember(node **root, char *key);

// function for creating a node
node *CreateNode(char key, int value)
{
    node *newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    
    if(newnode == NULL)
    {
        printf("Mem alloc failed\n");
        return newnode;
    }
    
    newnode->next = NULL;
    newnode->children = NULL;
    newnode->key = key;
    newnode->value = value;
    return newnode;
}

// function for creating root node
void CreateRoot(node **root)
{   
    // creates the root node with null character
    // and -1 value
    *root = CreateNode('\0', 0xffffffff);
}

//----------------------------------------------

void TrieAdd(node **root, char *key, int value)
{
    // sets a new node pointer
    node *nPtr = NULL;
    
    /*  checks if the previous CreateRoot
        returned null */
    if(*root == NULL)
    {
        printf("Tree is NULL\n");
        return;
    }
    
    printf("\nInserting key %s\n",key);
    
    nPtr = (*root)->children;
    
    /* checks if the root node has no children
       meaning this is the first node */
    if(nPtr == NULL)
    {
        
        for(nPtr = *root; *key; nPtr = nPtr->children)
        {
            // add each key as children of each parent node
            nPtr->children = CreateNode(*key, 0xffffffff);
            printf("Inserting [%c]\n",nPtr->children->key);
            key++;
        }
        nPtr->children = CreateNode('\0', value);
        printf("Inserting [%c]\n",nPtr->children->key);
        return;
    }
    
    // check first if inserting duplicates
    if(TrieIsMember(&nPtr, key))
    {
        printf("Key already exists\n");
        return;
    }
    
    /* if root->children != NULL
       traverse first the list while
       key == nPtr->key */
    while(*key != '\0')
    {
        if(*key == nPtr->key)
        {
            key++;
            printf("Traversing child [%c]\n", nPtr->children->key);
            nPtr = nPtr->children;
        }
        else break;
    }
    
    /* if a node has siblings, check if key
           is equal to the key of sibling node
           then advance key,
           call TrieAdd(address of nPtr sibling, and latest value of key)        
           proceed with processes then return.
       else 
           traverse sibling nodes until *key == sibling key
           or nPtr->next is NULL
    */
    while(nPtr->next)
    {
        if(*key == nPtr->next->key)
        {
            key++;
            TrieAdd(&(nPtr->next), key, value);
            return;
        }
        nPtr = nPtr->next;
    }
    
    /* creating a sibling node
       checks if key == \0 */
    if(*key)
        nPtr->next = CreateNode(*key, 0xffffffff);
    else
        nPtr->next = CreateNode(*key, value);
    
    printf("Inserting [%c] as sibling of [%c]\n",nPtr->next->key, nPtr->key);
    
    // if key == \0 stop the process after creating node
    if(!(*key)) return;
    
    key++; // advance key after inserting new sibling node
       
    /* inserting a new node at the sibling of the last
       traversed node */
    for(nPtr = nPtr->next; *key; nPtr = nPtr->children)
    {
        nPtr->children = CreateNode(*key, 0xffffffff);
        printf("Inserting [%c]\n",nPtr->children->key);
        key++;
    }
    nPtr->children = CreateNode('\0', value);
    printf("Inserting [%c]\n",nPtr->children->key);
    return;
     
}

/* intended for the TrieAdd lookup?? 
   validation if a node(children or sibling) exists 
   can be also used to check for existing keys */
node *TrieIsMember(node **root, char *key)
{   
    /* if the node passed is somewhere else
       other than TrieAdd.. root might start from the
       root node which contains null and \0
       
       (*root)->children if root->key = \0
       *root if root->key != \0
    */
    node *level = (*root)->key == '\0' ? (*root)->children : *root;
    
    while(1)
    {
        node *found = NULL;
        node *curr;
        
        for(curr = level; curr != NULL; curr = curr->next)
        {
            if(curr->key == *key)
            {
                found = curr;
                break;
            }
        }
        if(found == NULL)
            return NULL;
        if(*key == '\0')
            return curr;
        level = found->children;
        key++;
    }
} 

/* sample search implementation for searching keys
   returns true if the key is found in the trie
   false otherwise  
bool search(node *root, const char *key)
{
    node *curr = root->children;
    while(*key != '\0')
    {
        if(curr->key == *key)
        {
            curr = curr->children;
            key++;
        }
        else if(curr->next != NULL)
        {
            curr = curr->next;
        }
        else
            return false;
    }
    if(*key == '\0' && curr->key == '\0')
        return true;
    else
        return false;
}*/

// Removing key sample function
void removeNode(node *curr, node *prev, char *key)
{
    //node *curr = root->children;
    //node *prev = root;
    if(curr->key == '\0')
        return;
    
    if(curr->next && curr->next->key == key++)
    {
        key++;
        removeNode(curr->next, prev->children, key);
    }
    else if(curr->children && curr->children->key == key++)
    {
        key++;
        removeNode(curr->children, prev->children, key);
    }
    
    if(prev->

/*    if(ptr->next && prev->children != ptr)*/
/*    {*/
/*        prev->next = ptr->next;*/
/*        free(ptr);*/
/*        return;*/
/*    }*/
/*    else if(ptr->next && prev->children == ptr)*/
/*    {*/
/*        prev->children = ptr->next;*/
/*        free(ptr);*/
/*        return;*/
/*    }*/
/*    else if(ptr->next == NULL && prev->children != ptr)*/
/*    {*/
/*        prev->next = NULL;*/
/*        free(ptr);*/
/*        return;*/
/*    }*/
/*    else if(ptr->next == NULL && prev->children == ptr)*/
/*    {*/
/*        prev->children = NULL;*/
/*        free(ptr);*/
/*        return;*/
/*    }*/
    
}

void TrieDestroy()
{

}

int main(void)
{
    node *root;
    CreateRoot(&root);
    
/*    TrieAdd(&root, "amy", 20);*/
/*    TrieAdd(&root, "ann", 18);*/
/*    TrieAdd(&root, "annie", 18);*/
    TrieAdd(&root, "rob", 25);
    TrieAdd(&root, "robe", 16);
    TrieAdd(&root, "robin", 25);
    
    if(TrieIsMember(&root, "robe")) printf("Found\n");
    else printf("Not found\n");
    
}
