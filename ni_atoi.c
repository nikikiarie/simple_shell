#include "ni_shell.h"
/**
 * ni_atoi - converts str to int
 * @s: str
 * Return: int
 */
int ni_atoi(char *s)
{
	int i, a, z = 0;

	for (i = 0; s[i] != '\0' && (s[i]) >= '0' && s[i] <= '9'; i++)
	{
		a = s[i] - '\0';
		z = z * 10 + a;
	}
	return (z);
}
/**
 * ni_strl - returns str length
 * @a: str
 * Return: int
 */
unsigned int ni_strl(const char *a)
{
	unsigned int i = 0;

	while (*a++ != '\0')
		i++;
	return (i);
}
