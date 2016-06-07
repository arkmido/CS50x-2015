/*
    [WORKING]
    trie-0 main
    [c] simplestcodings
    
    
    compilation
    gcc -o trie-0 trie-0 trie-0-main.c -DDEBUG
*/
#include <stdio.h>
#include <stdlib.h>
#include "trie-0.h"

int main(){
    trieNode_t *root;
    printf("TRIE EXAMPLE\n\n");
    
    // Create a trie;
    TrieCreate(&root);
    
/*    TrieAdd(&root, "andrew", 1);*/
/*    TrieAdd(&root, "tina", 2);*/
/*    TrieAdd(&root, "argo", 3);*/
/*    TrieAdd(&root, "timor", 5);*/
/*    TrieRemove(&root, "tim");*/
/*    TrieAdd(&root, "tim", 6);*/
/*    TrieRemove(&root, "tim");*/
/*    TrieAdd(&root, "ti", 6);*/
/*    TrieAdd(&root, "amy", 7);*/
/*    TrieAdd(&root, "aramis", 8);*/

/*    TrieAdd(&root, "amy", 20);*/
/*    TrieAdd(&root, "ann", 18);*/
/*    TrieAdd(&root, "annie", 18);*/
/*    */
/*    TrieAdd(&root, "rob", 25);*/
    TrieAdd(&root, "robert", 16);
    
    //TrieRemove(&root, "tim");
    TrieRemove(&root, "robert");
    
/*    if(TrieSearch(root, "robert"))*/
/*        printf("Found!\n");*/
/*    else */
/*        printf("Not Found\n");*/
    
    // Destroy trie
    //TrieDestroy(root);
}
