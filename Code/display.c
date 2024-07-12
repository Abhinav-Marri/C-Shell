#include "display.h"
#include "header.h"

void display(){
    char temp[maxsize];
    getcwd(cwd, maxsize);
    if(strstr(cwd, homedir))
    {
        strcpy(temp, "~");
        memmove(temp+1, cwd + strlen(homedir), strlen(cwd)-strlen(homedir)); 
        temp[strlen(cwd)-strlen(homedir)+1] = '\0';
    }
    else{
        strcpy(temp, cwd);
    }   

    printf(WHITE "<" GREEN "%s@%s" WHITE ":" BLUE "%s" WHITE "$ ", user, sysname, temp);
    prompt = 1;
}





