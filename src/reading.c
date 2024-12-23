#include "my_shell.h"

char* reading(void){
    
    char *buf=NULL;
    size_t n=0;

    if (getline(&buf,&n,stdin)==-1){
        if (feof(stdin)) {  
        exit(EXIT_SUCCESS);  // We recieved an EOF
        }
        else{
        free(buf);
        perror("my_shell : error on reading\n");
        exit(EXIT_FAILURE);
        }
    }
    
    return buf;

}
