#include "ni_shell.h"
/**
 * ni_num - looks for num
 * @c: pointer
 * Return: null
 */
int ni_num(char *c)
{
	int i = 0;

	if (c[i] == '-')
		i++;
	for (; c[i] != '\0'; i++)
	{
		if (!isdigit(c[i]))
			return (0);
	}
	return (1);
}
