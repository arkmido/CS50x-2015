/*
    [FAILED]
    trie-1.c
    easy sample for tries
    [c] www.crazyforcode.com/trie-data-structure-implementation/
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* === node structure for the trie tree ===
    ~ end_str flag is set if there exists a string that ends
        at this node
    ~ next_char represents the next char of the string
*/
// node - each element in the trie tree
typedef struct node
{
    bool end_str;
    struct node *next_char[26];
}node;

// to insert stringin the trie tree
void insert(node *head, char *str)
{
    for(int i = 0; i < strlen(str); i++)
    {
        // if the child node is pointing to NULL
        if(head->next_char[str[i] - 'a'] == NULL)
        {
            // initialize new node
            node *n = (node *)malloc(sizeof(node));
            for(int j = 0; j < 26; j++)
            {
                n->next_char[j] = NULL;
            }
            n->end_str = false;
            head->next_char[str[i] - 'a'] = n;
            head = n;
        }
        // if the child node is not pointing to q
        else head = head->next_char[str[i] - 'a'];
    }
    // to mark the end_string flag for this string
    head->end_str = true;
}

// to check if the string is in the trie tree
bool check(node *head, char *str)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(head->next_char[str[i] - 'a'] == NULL) return false;
        else head = head->next_char[str[i] - 'a'];
    }
    // check if the end_string flag is true;
    if(head->end_str == true) return true;
    else return false;
}

// MAIN
int main()
{   
    // initialize head node
    node *head = (node *)malloc(sizeof(node));
    for(int i = 0; i < 26; i++)
    {
        head->next_char[i] = NULL;
    }
    head->end_str = false;
    
    char *str = "Hello, World";
    insert(head, str);
    
    if(check(head, str)) printf("present\n");
    else printf("not present\n");

    return 0;
}
