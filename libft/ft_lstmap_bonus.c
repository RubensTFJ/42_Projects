/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:26:02 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/20 19:06:11 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newmember;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	newlist = NULL;
	while (lst != NULL)
	{
		newmember = ft_lstnew((*f)(lst->content));
		if (!newmember)
		{
			ft_lstclear(&newlist, (*del));
			return (NULL);
		}
		ft_lstadd_back(&newlist, newmember);
		lst = lst->next;
	}
	return (newlist);
}
