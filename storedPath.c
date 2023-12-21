#include "shell.h"
/**
 * storedPath - function that looks for the command path
 * @command: command
 * Return: the path
 */
char *storedPath(char *command)
{
	int index = 0;
	char *path = NULL, *tokens = NULL;
	char *path_array[1000];
	char *new_path = NULL;
	size_t new_path_size;
	struct stat buf;

	path = strdup(_getenv("PATH")); /* gets a dup of PATH */
		if (path == NULL)
			free(path);
	tokens = strtok(path, ":"); /* split the path in a set of tokens */
	if (stat(command, &buf) == 0) /* in case of success */
	{
		strcpy(path, command);
		return (path); /* return a copy of command */
	}
	new_path_size = strlen(tokens) + 1 + strlen(command) + 1;
	new_path = realloc(new_path, new_path_size);
		if (new_path == NULL)
			free(new_path);
	while (tokens != NULL)
	{
		path_array[index] = tokens; /* store results of tokens in path_array */
		index++;
		tokens = strtok(NULL, ":");
	}
	if (tokens == NULL)
		path_array[index] = NULL;
	index = 0;
	while (path_array[index] != NULL)
	{
		strcpy(new_path, path_array[index]); /* copy tokens to new path */
		strcat(new_path, "/"); /* add "/" and command */
		strcat(new_path, command);
		strcat(new_path, "\0");
		if (stat(new_path, &buf) == 0) /* if sucess, free and return new_path */
		{
			free(path);
			return (new_path);
		}
		index++;
	}
	free(new_path);
	free(path);
	return (NULL);/* in case of possible errors */
}
