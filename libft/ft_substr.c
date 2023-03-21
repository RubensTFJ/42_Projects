/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:27:47 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/05 22:27:57 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;
	size_t		slength;

	if (!s)
		return (NULL);
	slength = ft_strlen(s);
	i = 0;
	while ((i + start) < slength && i < len)
		i++;
	sub = ft_calloc(sizeof(char), (i + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && (start + i) < slength)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}

// if (len > slength)
// 		len = slength;