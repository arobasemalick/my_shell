#ifndef __MY_SHELL_H__
#define __MY_SHELL_H__

//MACROS
#define DELIM " "

//LIBRARIES
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

//FUNCTIONS
//reading.c
char* reading(void);

//parsing.c
char **parsing(char* line);

//exec.c
int exec(char **args);

//builtin.c
int my_shell_cd(char **args);
int my_shell_env(char **args);
int my_shell_help(char **args);
int my_shell_exit(char **args);

//new_process.c
int new_process(char **args);

#endif
