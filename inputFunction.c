#include "shell.h"
/**
 * inputFunction - stock an input line.
 * Return: The input line as a string.
 */
char *inputFunction(void)
{
	char *input = NULL;
	size_t inputSize = 0;
	ssize_t inputLine = 0;

	inputLine = getline(&input, &inputSize, stdin);
	if (inputLine == -1)
	{
		free(input);
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline failed");
			exit(EXIT_FAILURE);
		}
	}
	input[inputLine - 1] = '\0';/*replace line jump by end of string*/
	return (input);
}
