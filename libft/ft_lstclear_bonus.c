/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:07:29 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/20 19:06:24 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*iterate;
	t_list	*delete;

	if (!lst || !del)
		return ;
	iterate = *lst;
	while (iterate)
	{
		delete = iterate;
		iterate = iterate->next;
		(*del)(delete->content);
		free(delete);
	}
	*lst = 0;
}
