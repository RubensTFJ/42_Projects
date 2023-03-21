/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:27:45 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/05 20:55:41 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		leng[2];
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	leng[0] = ft_strlen(s1);
	leng[1] = ft_strlen(s2);
	joined = ft_calloc(sizeof(char), (leng[0] + leng[1] + 1));
	if (!joined)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		joined[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		joined[i + j] = s2[j];
	return (joined);
}
