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
char *_getenv(char *name);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
void freeall(char *input, char *new_path);
int counterFunction(char *input);
int environPrinter(void);
#endif
