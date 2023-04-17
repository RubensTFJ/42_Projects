/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:20:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/15 02:34:21 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void    sb(t_list *list)
{
	int temp;

	if (!list || !list->next)
		return ;
	temp = list->content;
	list->content = list->next->content;
	list->next->content = temp;
	(*moves())++;
	ft_printf("sb\n");
}

void	pb(t_push *get)
{
	t_list  *first;

	if (!get->first.head)

		return;
	first = get->first.head;
	get->first.head = get->first.head->next;
	ft_lstadd_front(&get->second.head, first);
	(*moves())++;
	ft_printf("pb\n");
}

void	rb(t_list **list)
{
	t_list  *first;

	first = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, first);
	(*moves())++;
	ft_printf("rb\n");
}

void	rrb(t_stack *stack)
{
	t_list	*temp;
	t_list	*last;
	int		go;

	if (!stack->head)
		return ;
	temp = stack->head;
	go = 0;
	while (temp->next && go++ < (stack->size - 1))
		temp = temp->next;
	if (temp->next)
	{
		last = temp->next;
		temp->next = NULL;
		ft_lstadd_front(&stack->head, last);
	}
	(*moves())++;
	ft_printf("rrb\n");
}