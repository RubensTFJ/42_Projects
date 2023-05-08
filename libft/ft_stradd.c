/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:36:16 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/08 23:45:10 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stradd(char **original, char *add)
{
	int		i;
	int		j;
	char	*joined;

	if (!(*original) || !add)
		return ;
	joined = ft_calloc(sizeof(char),
		(ft_strlen((*original)) + ft_strlen(add) + 1));
	if (!joined)
		return ;
	i = -1;
	while ((*original)[++i])
		joined[i] = (*original)[i];
	j = -1;
	while (add[++j])
		joined[i + j] = add[j];
	free((*original));
	*original = joined;
}