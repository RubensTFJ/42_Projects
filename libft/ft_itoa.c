/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:27:33 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/18 20:21:51 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlength(long n);

char	*ft_itoa(int n)
{
	int		i;
	int		ssize;
	char	*ascii;
	long	longn;

	longn = n;
	ssize = intlength(longn);
	ascii = ft_calloc(sizeof(char), (ssize + 1));
	if (!ascii)
		return (NULL);
	i = -1;
	if (longn < 0)
	{
		ascii[0] = '-';
		longn = longn * (-1);
		i++;
	}
	ssize--;
	while (ssize > i)
	{
		ascii[ssize--] = (longn % 10) + 48;
		longn = longn / 10;
	}
	return (ascii);
}

static int	intlength(long n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = n * (-1);
	}
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}
