#include "shell.h"
/**
 * freeall - free all
 * @input: input variable
 * @newPath: new path variable
 */
void freeall(char *input, char *newPath)
{
	if (input != NULL)
	{
		free(input);
		input = NULL;
	}

	if (newPath != NULL)
	{
		free(newPath);
		newPath = NULL;
	}
}
