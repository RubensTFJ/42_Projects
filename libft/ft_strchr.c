/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:33:47 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/03 21:05:05 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (unsigned char)c)
			return (&((char *)string)[i]);
		i++;
	}
	if (string[i] == (unsigned char)c)
		return (&((char *)string)[i]);
	return (NULL);
}
