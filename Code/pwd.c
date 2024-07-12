#include "pwd.h"

int pwd(){
    char dir[1000];
    getcwd(dir, 1000);

    printf("%s\n", dir);
    
    return 0;
}
