#include "shell.h"
/**
 * main - command interpreter
 * Return: 0
 */
int main(void)
{
	char *input = NULL, **tokenArray = NULL, *newPath = NULL;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1) /* if interactive */
			printf("$ ");			   /*print prompt*/
		input = inputFunction();
		if (strcmp("env\n", input) == 0)
		{
			free(input);
			environPrinter();
			continue;
		}
		if (strcmp(input, "exit\n") == 0)
		{
			free(input);
			break;
		}
		tokenArray = tokeniseCommand(input, TOKEN_DELIMITER);
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
		if (newPath != NULL)
		{
			status = executeFunction(tokenArray, newPath);
			free(newPath);
		}
		freeTokenArray(tokenArray);
	}
	return (status);
}
