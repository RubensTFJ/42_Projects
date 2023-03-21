/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:33:25 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/03 19:37:30 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int		len;

	len = ft_strlen(string);
	while (len > -1)
	{
		if (string[len] == (char)c)
			return ((char *)&string[len]);
		len--;
	}
	return (NULL);
}
