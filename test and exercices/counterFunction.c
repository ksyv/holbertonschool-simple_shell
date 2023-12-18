#include "shell.h"
/**
 * counterFunction - function that return number of word in a string
 * make token with each part separated by a space (arg)
 * @input: the input command
 * Return: number of word
 */
int counterFunction(char *input)
{
	int count = 0;

	while (*input != '\0')
	{
		if (*input == ' ')
		{
			count++;
		}
		input++;
	}
	return (count);
}
