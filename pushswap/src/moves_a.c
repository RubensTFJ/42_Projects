/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:25:48 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/15 02:34:09 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void    sa(t_list *list)
{
	int temp;

	if (!list || !list->next)
		return ;
	temp = list->content;
	list->content = list->next->content;
	list->next->content = temp;
	(*moves())++;
	ft_printf("sa\n");
}

void	pa(t_push *get)
{
	t_list  *first;

	if (!get->second.head)
		return;
	first = get->second.head;
	get->second.head = get->second.head->next;
	ft_lstadd_front(&get->first.head, first);
	(*moves())++;
	ft_printf("pa\n");
}

void	ra(t_list **list)
{
	t_list  *first;

	first = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, first);
	(*moves())++;
	ft_printf("ra\n");
}

void	rra(t_stack *stack)
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
	ft_printf("rra\n");
}
