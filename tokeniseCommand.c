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

	if (strcmp(input, "exit") == 0)
	{
		write(1, "\nSee you soon!\n\n", 17);
		return (2);
	}
	if (strcmp(input, "env") == 0)
		return (_printenv());

	if (input[0] == 32)
	{
		input = NULL;
		return (1);
	}
	token = strtok(input, " ");
	while (token)
	{
		arg[index++] = token;
		token = strtok(NULL, " ");
	}
	arg[index] = NULL;
	return (executeFunction(arg));
}
