/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:17:33 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/20 19:06:18 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iterate;

	if (!lst || !f)
		return ;
	iterate = lst;
	while (iterate != NULL)
	{
		(*f)(iterate->content);
		iterate = iterate->next;
	}
}
