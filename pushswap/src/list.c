/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:34:38 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/15 03:27:37 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iterate;

	if (!lst)
		return (NULL);
	iterate = lst;
	while (iterate->next != NULL)
		iterate = iterate->next;
	return (iterate);
}