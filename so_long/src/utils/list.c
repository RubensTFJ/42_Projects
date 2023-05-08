/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:58:15 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/25 18:38:50 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_list	*ft_lstnew(t_object *content)
{
	t_list	*newnode;

	if (!content)
		return (NULL);
	newnode = ft_calloc(sizeof(t_list), 1);
	newnode->obj = content;
	newnode->next = NULL;
	return (newnode);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iterate;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		iterate = *lst;
		while (iterate->next)
			iterate = iterate->next;
		iterate->next = new;
	}
}

void	obj_stack_remove(t_object *list, t_object *remove)
{
	while (list->on_top && (list->on_top != remove))
	{
		list = list->on_top;
	}
	if (list->on_top == remove)
		list->on_top = list->on_top->on_top;
}

void	obj_stack_add(t_object *list, t_object *add)
{
	if (!list || !add)
		return ;
	while (list->on_top)
	{
		list = list->on_top;
	}
	list->on_top = add;
}
