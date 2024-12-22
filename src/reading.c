#include "my_shell.h"

char* reading(void){
    
    char *buf=NULL;
    size_t n=0;

    if (getline(&buf,&n,stdin)==-1){
        free(buf);
        perror("Error on reading\n");
        exit(EXIT_FAILURE);
    }
    
    return buf;

}
