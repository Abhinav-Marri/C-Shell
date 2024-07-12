#include "header.h"

char* user;
char* cwd;
char* homedir;
char* prevdir;
char* sysname;
int prompt;

int main(){

    user = (char*)malloc(maxsize);
    sysname = (char*)malloc(maxsize);
    cwd = (char*)malloc(maxsize);
    homedir = (char*)malloc(maxsize);
    prevdir = (char*)malloc(maxsize);

    getcwd(homedir, maxsize);
    strcpy(cwd, homedir);
    char *path = (char *)malloc(sizeof(char) * 100);
    strcpy(path, homedir);
    strcat(path, "/history.txt");

    strcpy(prevdir, "");

    gethostname(sysname, maxsize);
    user = getenv("USER");
    // system("cmd.exe /c echo %USERNAME%");
    // printf("%s\n",user);
    display();

    while(1){


        if(prompt == 1){
            char x[1000];
            fgets(x, sizeof(x), stdin);
            
            loghistory(x, path);

            char * point = x;
            int flag = 0;
            for (int i = 0; x[i] != '\0'; i++) {
                if (!isspace((unsigned char)x[i])) {
                    flag = 1;
                    break; 
                }
            }
            if(flag == 0){
                prompt = 0;
                continue;
            }   
            x[strlen(x) - 1] = '\0';
            char *command = strtok_r(point," \t",&point);
            char *message = point;
            // printf("%s \n%s\n",command,message);

        
                if(strcmp(command,"pwd") == 0){
                    pwd();
                
                }
                else if(strcmp(command,"echo") == 0){
                    echo(message);
                
                }
                else if(strcmp(command,"cd") == 0){
                    cd(message,prevdir);
                
                }
                else if(strcmp(command,"history") == 0){
                    history(path, x);
                }
                else if(strcmp(command,"exit") == 0){
                    printf("Exiting...\n");
                
                    return 0;
                }
                else{
                    printf("Unexpected input\n");
                }
            prompt = 0;
        }
        else{
            display();
        }
    }

    return 0;
}

