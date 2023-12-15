#include "ni_shell.h"

/**
 * ni_memcpy - copies string
 * @a: source
 * @z: dest
 * @i: holds count
 * Return: null
 */
void ni_memcpy(char *a, const char *z, size_t i)
{
	size_t j;

	for (j = 0; j < i; j++)
		a[j] = z[j];
}
/**
 * ni_input - reads user input
 * @b: holds string
 * Return: int
 */
int ni_input(char *b)
{
	int by = read(STDIN_FILENO, b, BUFFER_SIZE);

	if (by < 0)
	{
		write(STDERR_FILENO, "Error reading input\n", 20);
		exit(1);
	}
	return (by);
}
/**
 * ni_getline - gets input form cmd
 * @b: holds input
 * @by: variable holding string read
 * @p: variable tracking prompt
 * @l: holding promptposition
 * Return: null
 */
char *ni_getline(char *b, int *p, int by, int *l)
{
	char *a = malloc(BUFFER_SIZE);
	char z;

	if (!a)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (*p < by)
	{
		z = b[(*p)++];
		if (z == '\n')
		{
			a[*l] = '\0';
			return (a);
		}
		else
		{
			a[(*l)++] = z;
			if (*l % BUFFER_SIZE == 0)
				a = ni_line(a, l, *l + 1);
		}
	}
	free(a);
	return (NULL);
}
/**
 * ni_line - increase line buffer
 * @l: line
 * @i: int
 * @s: size
 * Return: char
 */
char *ni_line(char *l, int *i, int s)
{
	char *n;
	int a = s + BUFFER_SIZE;

	n = malloc(a);
	if (!n)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	ni_memcpy(n, l, *i);
	free(l);
	*i = 0;
	free(n);
	return (n);

}
