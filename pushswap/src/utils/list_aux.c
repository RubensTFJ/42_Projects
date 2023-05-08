/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:33:28 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/17 22:57:30 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iterate;

	if (!lst || !new)
		return ;
	iterate = *lst;
	if (*lst)
	{
		while (iterate->next)
			iterate = iterate->next;
		iterate->next = new;
		new->next = NULL;
	}
	else
		*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*newnode;

	newnode = ft_calloc(sizeof(t_list), 1);
	if (!newnode)
		return (NULL);
	newnode->content = content;
	return (newnode);
}

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*interate;

	if (!lst)
		return (0);
	counter = 0;
	interate = lst;
	while (interate)
	{
		counter++;
		interate = interate->next;
	}
	return (counter);
}

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
