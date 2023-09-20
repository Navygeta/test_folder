#include "zimbo.h"
/**
 * handle_commands - handles commands.
 * @input: input command
 * @argv: an array of strings
 * Return: 1 (Special Case)
 */
int handle_commands(char *input, char *argv[])
{
	char *ptr, **toks;
	int i = 0;

	ptr = input;
	while ((ptr = _memchr(ptr, ';', _strlen(ptr))) != NULL)
	{
		*ptr = '\0';
		ptr++;
	if (*ptr == '\0')
	{
		ptr++;
		continue;
	}
	toks = zimbo_split(input);
		if (toks == NULL)
		{
			return (-1);
		}
	i = zimbo_execute(toks, argv);
	free(toks);
	ptr++;
	input = ptr;
	}
	return (1);
}
