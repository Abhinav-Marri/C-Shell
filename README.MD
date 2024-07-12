# Assignment 3 : Building Shell

### Abhinav Marri <br> Roll No. 2021112015

> OS : _`WSL 2`_

## Project Overview :

- The objective was to build a interactive shell using c language which meets the following command requirements. <br>

  1. **pwd**
  2. **echo**
  3. **cd**
  4. **history**

## Description :

- All header files include the relevant libraries and contain function declarations.

The following are the functions of each C file :

- display.c
  - Handles the display of the shell, and displays user information, system information and current directory after every prompt.
- pwd.c
  - On entering the command 'pwd', the function prints the current working directory.
- echo.c
  - Echo is a similar to a print funciton.
  - Echo followed by any sentence will print the following sentence.
  - Command example : `echo Hi! my name is Abhinav`
  - Multiple spaces and tab spaces are printed as a single space.
- cd.c
  - cd corresponds to the change directory function.
  - cd handles cases such as the following commands are handled and perform the respective directory change.
    - `cd`
    - `cd .`
    - `cd ..`
    - `cd -`
    - `cd ~`
- history.c
  - Stores history of the shell, that is the past 20 commands given to the shell in a file named '_history.txt_'.
  - `history` command prints the last 10 commands saved.

Additional functionality :

- Unexpected input handling :
  - The shell prints out 'unexpected input' and prompts the user to enter a valid command.
- Error Handling :
  - Errors occuring are handled using 'perror'.
- Exit
  - The `exit` command exits out of the shell.

## How to Run :

- Make sure that all the files are present in the same directory.
- The following commands on any linux based system will run the shell.
  - > `make` or `make -f makefile`
  - > `./a.out`
