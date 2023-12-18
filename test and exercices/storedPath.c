#include "shell.h"
/**
 * command_path - function that looks for the command path
 * @cmd: command
 * Return: the path
 */
char *storedPath(char *cmd)
{
	int index = 0;
	char *path, *tokens;
	char *path_array[100];
	char *new_path = NULL;
	struct stat buf;

	path = strdup(_getenv("PATH")); /* gets a dup of PATH */
	tokens = strtok(path, ":"); /* split the path in a set of tokens */
	new_path = malloc(sizeof(char) * 100);
	if (_getenv("PATH")[0] == ':')
		if (stat(cmd, &buf) == 0) /* in case of success */
			return (strdup(cmd)); /* return a copy of command */

	while (tokens != NULL)
	{
		path_array[index] = tokens; /* store results of tokens in path_array */
		index++;
		tokens = strtok(NULL, ":");
	}
	path_array[index] = NULL;
	for (index = 0; path_array[index]; index++)
	{
		_strcpy(new_path, path_array[index]); /* copy tokens to new path */
		_strcat(new_path, "/"); /* add "/" and command */
		_strcat(new_path, cmd);
		_strcat(new_path, "\0");
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

	if (stat(cmd, &buf) == 0) /* After PATH checked and cmd is there locally */
		return (strdup(cmd));
	return (NULL);/* in case of possible errors */
}
