#include "my_shell.h"

char **parsing(char* line){

    int buffer=64;
    int i=0;
    char **tokens=malloc(buffer*sizeof(char*));
    char *token;

    if (!tokens){
        perror("Error on tokens allocation while parsing\n");
        return -1;
    }

    token = strtok(line,DELIM); //for first token

    while (token){   //token!=NULL
        if (token[0]=="#") //for the comments
            break;
        tokens[i]=token;
        i++;

    if (i>=buffer){
        buffer += buffer;
        tokens = realloc(tokens, buffer * sizeof(char *)); //add size to the buffer
    if (!tokens)
        {
            perror("Error on tokens allocation while parsing\n");
            return -1;
        }  
    }
    token=strtok(NULL,DELIM);    //for the other tokens
    }
    tokens[i] = NULL;
    return (tokens);

}
