#include "my_shell.h"

void exec(char **args){
    
    if (args[0]==NULL)      //empty command
        return -1;
    char *builtin_func_list[] = {
    "cd",
    "env",
    "help",
    "exit"
};
    int (*builtin_func[])(char **) = {
    &my_shell_cd,
    &my_shell_env,
    &my_shell_help,
    &my_shell_exit
};    

   for (int i=0; i < sizeof(builtin_func_list) / sizeof(char *); i++)   //look if the command is a builtin
{
   if (strcmp(args[0], builtin_func_list[i]) == 0)    // execute if there is a match
  {
        return ((*builtin_func[i])(args));
  }
 }
 return (new_process(args));  //new process creation
}

int my_shell_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Expected argument for \"cd\"\n");
        return 1; // Return error code
    }
    if (chdir(args[1]) != 0) {
        perror("cd");
        return 1; // Return error code
    }
    return 0; // Success
}

int my_shell_env(char **args) {
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
    return 0; // Success
}

int my_shell_help(char **args) {
    printf("Available built-in commands:\n");
    printf("cd: Change directory\n");
    printf("env: Display environment variables\n");
    printf("help: Show this help message\n");
    printf("exit: Exit the shell\n");
    return 0; // Success
}

int my_shell_exit(char **args) {
    printf("Exiting the shell...\n");
    exit(0); // Exit with success
}
