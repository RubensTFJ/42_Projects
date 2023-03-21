/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:41:01 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/04 22:46:00 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		length;
	char	*newstring;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	newstring = ft_calloc(sizeof(char), (length + 1));
	if (!newstring)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstring[i] = (*f)(i, s[i]);
		i++;
	}
	return (newstring);
}
