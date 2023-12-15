#include "ni_shell.h"

/**
 * main - entry
 * @void: no params
 * Return: 0
 */
int main(void)
{
	char *cmd = NULL;
	size_t m = 0;
	char d[] = " \t\n";

	while (1)
	{
		if (getline(&cmd, &m, stdin) == -1)
			break;
		if (cmd[strlen(cmd) - 1] == '\n')
			cmd[strlen(cmd) - 1] = '\0';
		ni_tokenizer(cmd, d);
	}
	free(cmd);
	return (0);
}
