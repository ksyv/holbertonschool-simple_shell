#include "shell.h"
/**
 * main - command interpreter
 * Return: 0
 */
int main(void)
{
	char *input = NULL;
	char **tokenArray = NULL;
	char *separator = " ";
	int status = 0;
	char *newPath = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1) /* if interactive */
			printf("$ ");			   /*print prompt*/
		input = inputFunction();
		if (strcmp("env", input) == 0)
		{
			environPrinter();
			continue;
		}
		if (strcmp(input, "exit") == 0)
			break;
		tokenArray = tokeniseCommand(input, separator);
		if (*tokenArray == NULL)
		{
			freeTokenArray(tokenArray);
			continue;
		}
		newPath = storedPath(*tokenArray);
		if (newPath == NULL)
		{
			perror("./hsh");
			free(newPath);
			freeTokenArray(tokenArray);
			return (3);
		}
		else
		{
			status = executeFunction(tokenArray, newPath);
			free(newPath);
		}
		freeTokenArray(tokenArray);
	}
	return (status);
}
