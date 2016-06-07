#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#define _GNU_SOURCE

int main(void)
{
    char *line = "GET /hello.php?name=kramers HTTP/1.1\r\n";
    char *root = "/home/jharvard/Dropbox/pset6/server";
    
    // request validation test
    // look for GET, HTTP/1.1 , \"
    if(!strstr(line, "GET"))
        printf("405 method not allowed\n");
    else if(!strstr(line, "HTTP/1.1"))
        printf("500 VERSION NOT SUPPORTED\n");
    
    // extracting request target
    char *sp1 = strstr(line, " ");
    char *sp2 = strrchr(line, ' ');
    int len = ((int)sp2) - ((int)sp1+1);
    char req_target[len];
    strncpy(req_target, sp1+1, len);
    req_target[len] = '\0';
    
    // validating request target
    if(req_target[0] != '/' || !strstr(req_target, "."))
        printf("501 not implemented\n");
    else if(strstr(req_target, "\""))
        printf("400 Bad request\n");
    
    printf("%s\n", req_target);
    
    // validating query
    char query[] = "";
    sp1 = strstr(req_target, "?name=");
    if(sp1 != NULL)
    {
        len = strlen(sp1+1);
        strncpy(query, sp1+1, len+1);
    }
    printf("%s\n", query);
    
    // concatenating root and request target
    char filename[0];
    for(int i = 0, n = strlen(req_target); i < n; i++)
    {
        if(req_target[i] == '?'&& req_target[i+1] == 'q')
            break;
        else
            filename[i] = req_target[i];
    }
    char path[strlen(root) + strlen(filename)];

    strcpy(path, root);
    strcat(path, filename);
    char *replace = strstr(path, "server");
    strncpy(replace, "public", 6);
    
    path[strlen(path)] = '\0';
    
    printf("%s\n", path);
    
    if(access(path, F_OK) == -1)
        printf("Path doesn't exists\n");
    else
        printf("Path exists\n");
        
    if(access(path, R_OK) == -1)
        printf("file not readable\n");
    else
        printf("file's readable\n");
    
    char extension[0];
    char *ext = strstr(filename, ".");
    strncpy(extension, ext+1, strlen(ext));
    
    printf("extension: %s\n", extension);
   
    return 0;
}
