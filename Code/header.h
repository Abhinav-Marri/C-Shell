#include "pwd.h"
#include "echo.h"
#include "history.h"
#include "cd.h"
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "string.h"
#include "display.h"
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

#define maxsize 1000
#define YELLOW "\033[00;33m"
#define CYAN "\033[00;36m"
#define WHITE "\033[00;37m"
#define GREEN "\e[1;92m"
#define PURPLE "\e[0;35m"
#define BLUE "\e[1;94m"

extern char* user;
extern char* cwd;
extern char* homedir;
extern char* prevdir;
extern char* sysname;
extern int prompt;
// extern char hist[20][maxsize];