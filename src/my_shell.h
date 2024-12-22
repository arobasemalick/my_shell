#ifndef __MY_SHELL_H__
#define __MY_SHELL_H__

//CONSTS
#define DELIM " "

//LIBRARIES
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//FUNCTIONS
char* reading(void);
char **parsing(char* line);

#endif