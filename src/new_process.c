#include "my_shell.h"

int new_process(char **args){
    pid_t pid;
    int status;

    pid=fork();   //create a child process

    if (pid==0){
        if (execvp(args[0], args) == -1)
            {
                perror("Error on child process in new_process");
            }
        exit(EXIT_FAILURE);
    }
    else if (pid<0){
        perror("Error on fork in new_process");
    }
    else {
        do {
            waitpid(pid, &status, WUNTRACED);
        }
        while (!WIFEXITED(status) && !WIFSIGNALED(status));        
    }

    return -1;
}
