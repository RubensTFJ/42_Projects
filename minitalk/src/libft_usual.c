#include <minitalk.h>

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

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	while ((8 < nptr[i] && nptr[i] < 14) || nptr[i] == 32)
		i++;
	sign = (nptr[i] != '-') - (nptr[i] == '-');
	i += (nptr[i] == '-' || nptr[i] == '+');
	number = 0;
	while (47 < nptr[i] && nptr[i] < 58)
		number = (nptr[i++] - 48) + (number * 10);
	return ((int)(number * sign));
}