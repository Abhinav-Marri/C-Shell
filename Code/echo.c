#include "echo.h"

int echo(char *message)
{
    char *token;

    // if(message[0] == '\"'){
    //     printf("%s",strtok(message,"\""));
    //     // return 0;
    // }
    // else{
        while (token = strtok_r(message, " \t", &message))
        {

            printf("%s ", token);

        }
    // }

    printf("\n"); //newline
    return 0;
}