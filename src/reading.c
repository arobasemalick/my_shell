#include "my_shell.h"

char* reading(void){
    
    char *buf=NULL;
    size_t n=NULL;

    if (getline(&buf,&n,stdin)==-1){
        free(buf);
        perror("Error on reading\n");
        return -1;
    }
    
    return buf;

}
