/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:20:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/17 22:56:35 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	sb(void)
{
	t_list	*list;
	int		temp;

	list = get()->second.list;
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

	if (!get()->first.list)
		return ;
	first = get()->first.list;
	get()->first.list = get()->first.list->next;
	ft_lstadd_front(&get()->second.list, first);
	get()->moves++;
	ft_printf("pb\n");
}

void	rb(void)
{
	t_list	**list;
	t_list	*first;

	list = &get()->second.list;
	first = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, first);
	get()->moves++;
	ft_printf("rb\n");
}

void	rrb(void)
{
	t_stack	*stack;
	t_list	*temp;
	t_list	*last;
	int		go;

	stack = &get()->second;
	if (!stack->list)
		return ;
	temp = stack->list;
	go = 0;
	stack->size = ft_lstsize(stack->list);
	while (temp->next && go++ < (stack->size - 1))
		temp = temp->next;
	if (temp->next)
	{
		last = temp->next;
		temp->next = NULL;
		ft_lstadd_front(&stack->list, last);
	}
	get()->moves++;
	ft_printf("rrb\n");
}
