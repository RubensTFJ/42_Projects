/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:32:21 by rteles-f          #+#    #+#             */
/*   Updated: 2022/10/29 19:44:39 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t xsize)
{
	char	*new;

	new = malloc(n * xsize);
	if (!new)
		return (NULL);
	ft_bzero(new, (n * xsize));
	return (new);
}
