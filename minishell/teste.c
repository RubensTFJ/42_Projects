#include <stdio.h>
#include <unistd.h>

# define HERE write(1, "here\n", 5)
# define THERE write(1, "there\n", 6)

int	split_case(char *line)
{
	if (!*line)
		return (0);
	else if (*line == '<' && *(line + 1) == '<')
		return (2);
	else if (*line == '>' && *(line + 1) == '>')
		return (2);
	else if (*line == '>' || *line == '<')
		return (1);
	return (0);
}

int	ignore_quotes(char *string)
{
	int		i;
	char	stop;

	i = 0;
	if (string[i] == '\"' || string[i] == '\'')
	{
		stop = string[i++];
		while (string[i] && string[i] != stop)
			i++;
	}
	return (i);
}

static int	getwords(char *s, char c)
{
	int		i;
	int		count;
	int		size;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		size = split_case(&s[i]);
		count += (s[i] && (s[i] != c));
		i += size + ignore_quotes(&s[i]); 
		while (s[i] && s[i] != c && !split_case(&s[i]) && !size)
			i++;
	}
	return (count);
}

void	force_space(char *line)
{
	int		i;
	char	stop;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			stop = line[i++];
			while (line[i] && line[i] != stop)
				i++;
		}
		if (line[i] == ' ')
			line[i] = -1;
		i++;
	}
}

int main(int c, char **v)
{
	HERE;
	force_space(v[1]);
	THERE;
	getwords(v[1], -1);
}