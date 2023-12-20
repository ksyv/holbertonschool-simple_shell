# include "shell.h"
/**
 * tokeniseCommand - function that reads the command and
 * make token with each part separated by a space (arg)
 * @input: the input string command
 * @separator: separator of token
 * Return: token array
 */
char **tokeniseCommand(char *input, char *separator)
{
	char **tokenArray = NULL;
	char *token = NULL;
	int index = 0;
	int size = 64;

	tokenArray = (char **)malloc(sizeof(char *) * size);
	if (!tokenArray)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, separator);
	while (token != NULL)
	{
		if (index >= size - 1)
		{
			size *= 2;
			tokenArray = realloc(tokenArray, sizeof(char *) * size);
			if (!tokenArray)
			{
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
		}
		tokenArray[index] = strdup(token);
		if (!tokenArray[index])
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		index++;
		token = strtok(NULL, separator);
	}

	tokenArray[index] = NULL;
	free(input);
	return (tokenArray);
}
/**
 * freeTokenArray - Frees memory allocated for the Token Array.
 * @tokenArray: array to free.
 */
void freeTokenArray(char **tokenArray)
{
	int index;

	for (index = 0; tokenArray[index] != NULL; index++)
	{
		free(tokenArray[index]);
	}
	free(tokenArray);
}
