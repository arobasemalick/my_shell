#include "my_shell.h"

int exec(char **args){
    
    if (args[0]==NULL)      //empty command
        return -1;
    char *builtin_func_list[] = {"cd\n","env\n","help\n","exit\n"};   /*args[0] does have a "\n" for a reason that I don't know yet
    For cd there are both cases and I also don't know why*/
    int (*builtin_func[])(char **) = {&my_shell_cd,&my_shell_env,&my_shell_help,&my_shell_exit};    

   for (size_t i=0; i < sizeof(builtin_func_list) / sizeof(char *); i++)   //look if the command is a builtin
    {   
        if (strcmp(args[0], builtin_func_list[i]) == 0)    // execute if there is a match
    {
            return ((*builtin_func[i])(args));
    }
    }
    return (new_process(args));  //new process creation
}
