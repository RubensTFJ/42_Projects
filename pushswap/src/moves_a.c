/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:25:48 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/17 22:55:33 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	sa(void)
{
	t_list	*list;
	int		temp;

	list = get()->first;
	if (!list || !list->next)
		return ;
	temp = list->content;
	list->content = list->next->content;
	list->next->content = temp;
	get()->moves++;
	ft_printf("sa\n");
}

void	pa(void)
{
	t_list	*first;

	first = get()->first;
	if (!get()->second)
		return ;
	first = get()->second;
	get()->second = get()->second->next;
	ft_lstadd_front(&get()->first, first);
	get()->moves++;
	ft_printf("pa\n");
}

void	ra(void)
{
	t_list	**list;
	t_list	*first;

	list = &get()->first;
	if (!list || !(*list) || !(*list)->next)
		return ;
	first = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, first);
	get()->moves++;
	ft_printf("ra\n");
}

void	rra(void)
{
	t_list	*temp;
	t_list	*last;

	if (!get()->first)
		return ;
	temp = get()->first;
	while (temp->next && temp->next->next)
		temp = temp->next;
	if (temp->next)
	{
		last = temp->next;
		temp->next = NULL;
		ft_lstadd_front(&get()->first, last);
		ft_printf("rra\n");
		get()->moves++;
	}
}
