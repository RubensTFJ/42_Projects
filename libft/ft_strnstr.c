/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:33:38 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/05 22:48:32 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	littlelen;

	littlelen = ft_strlen(little);
	if (littlelen == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && ((int)i < (int)(len - littlelen + 1)
		|| (int)len < 0))
	{
		if (!ft_strncmp(&((const char *)big)[i], little, littlelen))
			return (&((char *)big)[i]);
		i++;
	}
	return (NULL);
}
