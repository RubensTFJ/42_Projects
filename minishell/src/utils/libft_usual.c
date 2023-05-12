#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *string);
void	*ft_calloc(size_t n, size_t xsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*sttc_itoa(int number);
char	*ft_itoa(int number);
void	free_biarray(void **arg, int size);

void	*ft_calloc(size_t n, size_t xsize)
{
	char	*new;
	size_t	i;
	size_t	total;

	total = (n * xsize);
	new = malloc(total);
	if (!new)
		return (NULL);
	i = 0;
	while (i < total)
		new[i++] = 0;
	return (new);
}

// char	*ft_stradd(char **original, char *add)
// {
// 	int		i;
// 	int		j;
// 	char	*joined;

// 	if (!(*original) || !add)
// 		return ;
// 	joined = ft_calloc(sizeof(char),
// 		(ft_strlen((*original)) + ft_strlen(add) + 1));
// 	if (!joined)
// 		return ;
// 	i = -1;
// 	while ((*original)[++i])
// 		joined[i] = (*original)[i];
// 	j = -1;
// 	while (add[++j])
// 		joined[i + j] = add[j];
// 	free((*original));
// 	*original = joined;
// 	return (joined);
// }

int	ft_strlen(const char *string)
{
	int	counter;

	counter = 0;
	while (string[counter])
		counter++;
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	joined = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = -1;
	while (s1[++i])
		joined[i] = s1[i];
	j = -1;
	while (s2[++j])
		joined[i + j] = s2[j];
	return (joined);
}

char	*sttc_itoa(int number)
{
	static char	to_ascii[12];
	int			index;
	int			sign;

	sign = (number > 0) - (number < 0);
	index = 11;
	while (number || index == 11)
	{
		to_ascii[--index] = (number % 10) * sign + '0';
		number = number / 10;
	}
	if (sign < 0)
		to_ascii[--index] = '-';
	return (&to_ascii[index]);
}

char	*ft_itoa(int number)
{
	char	to_ascii[12];
	char	*string;
	int		index;
	int		sign;

	sign = (number > 0) - (number < 0);
	index = 11;
	while (number || index == 11)
	{
		to_ascii[--index] = (number % 10) * sign + '0';
		number = number / 10;
	}
	if (sign < 0)
		to_ascii[--index] = '-';
	string = ft_calloc(sizeof(char), (12 - index));
	if (!string)
		return (NULL);
	sign = 0;
	while (index < 11)
		string[sign++] = to_ascii[index++];
	return (string);
}

void	free_biarray(void **arg, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(arg[i++]);
	free(arg);
}