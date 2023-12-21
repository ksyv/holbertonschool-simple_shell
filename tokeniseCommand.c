# include "shell.h"
/**
 * tokeniseCommand - function that reads the command and
 * make token with each part separated by a space (arg)
 * @input: the input command
 * @inputSize: unused
 * Return: command execution
 */
int tokeniseCommand(char *input, __attribute__((unused))size_t inputSize)
{
	char *token = NULL;
	char *arg[100];
	int index = 0;

	if (strcmp(input, "env") == 0)
		return (environPrinter());
	if (input[0] == 32)
	{
		input = NULL;
		return (1);
	}
	if (strcmp(input, "exit") == 0)
		return (2);
	token = strtok(input, " ");
	while (token)
	{
		arg[index] = token;
		index++;
		token = strtok(NULL, " ");
	}
	while (index <= 100)
	{
		arg[index] = NULL;
		index++;
	}
	return (executeFunction(arg));
}
