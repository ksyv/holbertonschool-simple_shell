#ifndef __MYSHELL__
#define __MYSHELL__
/*Include all the necessaries library*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
int tokeniseCommand(char *s, size_t file_stream);
int executeFunction(char *arg[]);
char *storedPath(char *command);
#endif
