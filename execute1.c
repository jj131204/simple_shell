#include "holberton.h"
/**
 *execute - check  if the command recived is true.
 *
 *@tokens: recives the value of  the funcion token.
 *
 *@line: arguments received
 *
 *Return: return (1).
 */
int execute(char **tokens, char *line)
{
	pid_t pid;
	int i = 0;
	char path[1024] = "/bin";

	while (line[i] == ' ')
		i++;

	if (line[i] == path[0])
	{
		_strcpy(path, *tokens);
	}

	else if (tokens[0])
	{
		_strcat(path, "/"), _strcat(path, *tokens);
	}
	else
	{
		*tokens = NULL;
		line = NULL;
		return (0);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, tokens, environ) == -1)
		{
			errors(tokens);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		errors(tokens);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

	return (1);
}
