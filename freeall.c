#include "shell.h"
/**
 * freeall - free all
 * @input: input variable
 * @new_path: new path variable
 */
void freeall(char *input, char *new_path)
{
	if (input != NULL)
	{
		free(input);
		input = NULL;
	}

	if (new_path != NULL)
	{
		free(new_path);
		new_path = NULL;
	}
}
