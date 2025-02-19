#include "my_shell.h"

char **parsing(char* line){

    int buffer=64;
    int i=0;
    char **tokens=malloc(buffer*sizeof(char*));
    char *token;

    // Remove the trailing '\n', if any
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }

    if (!tokens){
        perror("my_shell : error on tokens allocation while parsing\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line,DELIM); //for first token

    while (token){   //token!=NULL
        if (token[0]=='#') //for the comments
            break;
        tokens[i]=token;
        i++;

    if (i>=buffer){
        buffer += buffer;
        tokens = realloc(tokens, buffer * sizeof(char *)); //add size to the buffer
    if (!tokens)
        {
            perror("my_shell : error on tokens allocation while parsing\n");
            exit(EXIT_FAILURE);
        }  
    }
    token=strtok(NULL,DELIM);    //for the other tokens
    }
    tokens[i] = NULL;
    return (tokens);

}
