/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_usual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:24:26 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/08 18:28:34 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
	}
	return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
}
