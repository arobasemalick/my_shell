#include "my_shell.h"

int new_process(char **args){
    pid_t pid;
    int status;

    pid=fork();   //create a child process

    if (pid==0){  // on the child process
        if (execvp(args[0], args) == -1)
            {
                perror("my_shell : error on child process in new_process");
            }
        exit(EXIT_FAILURE);
    }
    else if (pid<0){  // error handling
        perror("my_shell : error on fork in new_process");
    }
    else {  //parent process
        do {
            waitpid(pid, &status, WUNTRACED);  //waiting for the child process to change status
        }
        while (!WIFEXITED(status) && !WIFSIGNALED(status));        
    }

    return -1;
}
