/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:55:08 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/20 19:06:04 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*interate;

	if (!lst)
		return (0);
	counter = 1;
	interate = lst;
	while (interate->next != NULL)
	{
		counter++;
		interate = interate->next;
	}
	return (counter);
}
