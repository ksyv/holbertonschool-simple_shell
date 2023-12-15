#include "shell.h"
/**
 * *_strdup - copy a given string and return pointer
 *  @str: the string
 *  Return: the adress of the new string
 */
char *_strdup(char *str)
{
	char *st = NULL;
	int i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		continue;
	st = malloc((i + 1) * sizeof(char));
	if (st == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		st[i] = str[i];
	return (st);
}
/**
 * _printenv - it displays all the variables in the environment system
 *
 * Return: 0
 */
int _printenv(void)
{
	char *str = environ[0];
	int index = 0, file_descr = 1;

	while (str[index] != '\0')
	{
		write(file_descr, str, strlen(str));
		write(file_descr, "\n", 1);
		str = environ[index]; /*++i without next line */
		++index;
	}
	return (0);
}
