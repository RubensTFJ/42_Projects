/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:20:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/23 10:18:38 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	sb(void)
{
	t_list	*list;
	int		temp;

	list = get()->second;
	if (!list || !list->next)
		return ;
	temp = list->content;
	list->content = list->next->content;
	list->next->content = temp;
	get()->moves++;
	ft_printf("sb\n");
}

void	pb(void)
{
	t_list	*first;

	if (!get()->first)
		return ;
	first = get()->first;
	get()->first = get()->first->next;
	ft_lstadd_front(&get()->second, first);
	get()->moves++;
	ft_printf("pb\n");
}

void	rb(void)
{
	t_list	**list;
	t_list	*first;

	list = &get()->second;
	if (!list || !(*list) || !(*list)->next)
		return ;
	first = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, first);
	get()->moves++;
	ft_printf("rb\n");
}

void	rrb(void)
{
	t_list	*temp;
	t_list	*last;

	if (!get()->second)
		return ;
	temp = get()->second;
	while (temp->next && temp->next->next)
		temp = temp->next;
	if (temp->next)
	{
		last = temp->next;
		temp->next = NULL;
		ft_lstadd_front(&get()->second, last);
		ft_printf("rrb\n");
		get()->moves++;
	}
}
