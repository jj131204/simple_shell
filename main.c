#include "holberton.h"

/**
 *main - start de simple_shell
 *
 *Return: return(0);
 */

int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int num;
	char *str = "#C_isfun$ ";
	char *tok[100];
	int validators = 1;

	signal(SIGINT,  sigint_handler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, str, 10);
		}
		num = getline(&line, &bufsize, stdin);
		if (num == EOF)
		{
			free(line);
			return (0);
		}


		token(line, tok);
		validators = line_validator(tok);

		if (validators == 0)
		{
			free(line);
			return (0);
		}
		else
		{
			execute(tok, line);
		}
	}
	free(line);
	return (0);
}
