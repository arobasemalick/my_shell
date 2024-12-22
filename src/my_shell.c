#include "my_shell.h"

void my_shell(void){
    char *line;
    char **args;
    int status=-1;

    do {
        printf("my_shell> ");
        line=reading();
        args=parsing(line);
        status=exec(args);

        //avoid memory leaks
        free(line);
        free(args);

        if (status>=0)
            exit(status);
    } while(status == -1);
    

}
