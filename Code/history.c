#include "history.h"

void loghistory(char *command, char *path)
{
    char buffer[maxsize];
    int count = 0, i = 0,same_flag = 1; //assume the same command as last is recieved.
    char store[maxsize];

    FILE *f = fopen(path, "a+");

    if (f == NULL){
        perror("History");
    }
    
    while (fgets(buffer, maxsize, f) != NULL) // Counts number of lines in file.
    {
        count++;
    }

    fclose(f);

    f = fopen(path, "a+");

    while (fgets(buffer, maxsize, f) != NULL) // check with last command
    {
        strcpy(store, buffer);
    }

    fclose(f);


    if (strlen(store) != strlen(command))
    {
        same_flag = 0;
    }
    if (same_flag == 0) // checking similarity.
    {
        while (command[i] != '\0' && store[i] != '\0')
        {
            if (command[i] != store[i])
            {

                same_flag = 0;
                break;
            }
            i++;
        }
    }

    if (same_flag == 0)
    {

        if (count < 20) // just append the new command.
        {
            FILE *f;
            f = fopen(path, "a");
            fprintf(f, "%s", command);
            fclose(f);
        }

        else
        {
            FILE *f = fopen(path, "a+");
            FILE *temp = fopen("temp.txt", "w");

            if (f == NULL){
                perror("History");
            }
            if (temp == NULL){
                perror("History");
            }

            fgets(buffer, maxsize, f);

            while (fgets(buffer, maxsize, f) != NULL)
            {
                fprintf(temp, "%s", buffer);
            }

            fclose(f);
            fclose(temp);

            temp = fopen("temp.txt", "a+");

            if (temp == NULL){
                perror("History");
            }
            
            f = fopen(path, "w");

            if (f == NULL){
                perror("History");
            }

            while (fgets(buffer, maxsize, temp) != NULL)
            {
                fprintf(f, "%s", buffer);
            }

            fclose(f);
            fclose(temp);

            // adding last command

            f = fopen(path, "a+");
            fprintf(f, "%s", command);
            fclose(f);

            remove("temp.txt");
        }
    }

    return;
}


void history(char* path, char* comm){
    FILE * f = fopen(path,"r");
    if(f == NULL){
        printf("Error opening history file\n");
        return;
    }
    char temp[maxsize];
    int line_count = 0;

    while (fgets(temp, sizeof(temp), f) != NULL) {
        line_count++;
    }
    // printf("%d\n",line_count);
    char line[maxsize];

    fseek(f, 0, SEEK_SET);

    int i = 0;

    if(line_count < 10){
        while (fgets(line, sizeof(line), f) != NULL) { 
            printf("%s", line);
        }
        fclose(f);
        return;
    }
    else{
    while (fgets(line, sizeof(line), f) != NULL){ 
        if(i >= line_count - 10){
            printf("%s", line);
        }
        i++;
    }
    }

    fclose(f);
    return;

}
