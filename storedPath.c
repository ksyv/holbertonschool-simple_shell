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
	char *path_array[100];
	char *new_path = NULL;
	struct stat buf;

	path = strdup(_getenv("PATH")); /* gets a dup of PATH */
	tokens = strtok(path, ":"); /* split the path in a set of tokens */
	new_path = malloc(sizeof(char) * 100);
	if (_getenv("PATH")[0] == ':')
	{
		if (stat(command, &buf) == 0) /* in case of success */
			return (strdup(command)); /* return a copy of command */
	}
	while (tokens != NULL)
	{
		path_array[index++] = tokens; /* store results of tokens in path_array */
		tokens = strtok(NULL, ":");
	}
	for (index = 0; path_array[index]; index++)
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
		else
			new_path[0] = 0;
	}
	free(path);
	free(new_path);
	if (stat(command, &buf) == 0)
		return (_strdup(command));
	return (NULL);/* in case of possible errors */
}
