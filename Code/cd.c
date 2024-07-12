#include "cd.h"
#include <errno.h>

int cd(char* message, char* prevdir) {
    char* temp;
    char message_c[100]; 
    char*token;
    temp = (char*)malloc(maxsize);
    int count = 0;
    
    strcpy(message_c, message);

    token = strtok(message_c, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    if(count > 1){
        errno = E2BIG;
        perror("cd");
        return 1;
    }

    if(message[0] == '~'){
        char temp[maxsize];
        strcpy(temp,homedir);
        strcat(temp,message+1);
        strcpy(message,temp);
    }

    if (strcmp(message, "\0") == 0) {
        getcwd(temp, maxsize);
        if (chdir(homedir) == -1) {
            perror("cd: Could not change to home directory");
            return 1;
        }
        strcpy(prevdir,temp);
        
    } else if (strcmp(message, ".") == 0) {
        getcwd(temp, maxsize);
        strcpy(prevdir,temp);
    } else if (strcmp(message, "-") == 0) {
        getcwd(temp, maxsize);
        if (chdir(prevdir) == -1) {
            perror("cd: Could not change to previous directory");
            return 1;
        }
        strcpy(prevdir,temp);
    } else if (strcmp(message, "~") == 0) {
        getcwd(temp, maxsize);
        if (chdir(homedir) == -1) {
            perror("cd: Could not change to home directory");
            return 1;
        }
        strcpy(prevdir,temp);
        
    } else if (strcmp(message, "..") == 0) {
        getcwd(temp, maxsize);
        if (chdir("..") == -1) {
            perror("cd: Could not change to parent directory");
            return 1;
        }
        strcpy(prevdir,temp);
    } else {
        getcwd(temp, maxsize);
        if (chdir(message) == -1) {
            perror("cd: Could not change to target directory ");
            return 1;
        }
        strcpy(prevdir,temp);
    }

    return 0;
}
