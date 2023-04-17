/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:21:52 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/15 03:06:17 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	silent_ra(t_list **list)
{
	t_list  *first;

	first = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, first);
}

void	silent_rb(t_list **list)
{
	t_list  *first;

	first = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, first);
}

void	rr(t_push *get)
{
	silent_ra(&get->first.head);
	silent_rb(&get->second.head);
	(*moves())++;
	ft_printf("rr\n");
}

void	rrr(t_push *get)
{
	rra(&get->first);
	rra(&get->second);
	(*moves())++;
	ft_printf("rrr\n");
}

void	ss(t_push *get)
{
	sa(get->first.head);
	sa(get->second.head);
	(*moves())++;
	ft_printf("ss\n");
}
