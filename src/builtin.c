#include "my_shell.h"

int my_shell_cd(char **args) {
    if (!args[1]) {
        fprintf(stderr, "Expected argument for \"cd\"\n");
        return -1;
    }
    if (chdir(args[1]) != 0) {
        perror("cd");
    }
    return -1; // to return on my_shell
}

int my_shell_env(char **args) {
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
    return -1;
}

int my_shell_help(char **args) {
    printf("Available built-in commands in my_shell:\n");
    printf("cd: Change directory\n");
    printf("env: Display environment variables\n");
    printf("help: Show this help message\n");
    printf("exit: Exit my_shell\n");
    return -1;
}

int my_shell_exit(char **args) {
    printf("Exiting my_shell...\n");
    sleep(1);  
    exit(0); // Exit with success
}
