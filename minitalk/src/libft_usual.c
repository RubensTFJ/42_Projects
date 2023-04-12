/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_usual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:43:40 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/12 22:43:47 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
