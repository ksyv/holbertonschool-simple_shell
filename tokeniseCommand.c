# include "shell.h"
/**
 * tokeniseCommand - function that reads the command and
 * make token with each part separated by a space (arg)
 * @input: the input command
 * @inputSize: unused
 * Return: command execution
 */
int tokeniseCommand(char *input, size_t inputSize)
{
	char *token = NULL;
	char *arg[100];
	int index = 0;

	token = strtok(input, " ");
	while (token)
	{
		arg[index++] = token;
		token = strtok(NULL, " ");
	}
	arg[index] = NULL;
	return (executeFunction(arg));
}
