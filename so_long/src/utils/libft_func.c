/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:22:32 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/25 18:13:12 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t n, size_t xsize)
{
	char		*new;
	size_t		i;

	n *= xsize;
	new = malloc(n);
	if (!new)
		return (NULL);
	i = 0;
	while (i < n)
		new[i++] = 0;
	return (new);
}

int	is_in_str(char c, char *string)
{
	while (*string)
		if (c == *string++)
			return (1);
	return (0);
}

int	bl_strlen(char *string)
{
	int	i;

	i = 0;
	while (string && string[i] && string[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_itoa(int number)
{
	static char	str_number[12];
	int			index;
	char		sign;

	sign = 0;
	if (number < 0)
		sign = '-';
	index = 11;
	while (number > 0 || index == 11)
	{
		index--;
		str_number[index] = (number % 10) + '0';
		number = number / 10;
	}
	if (sign)
	{
		index--;
		str_number[index] = sign;
	}
	return (&str_number[index]);
}
