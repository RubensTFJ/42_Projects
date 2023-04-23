/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:21:52 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/23 10:21:56 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	silent_ra(void)
{
	t_list	**list;
	t_list	*first;

	list = &get()->first;
	if (!list || !(*list) || !(*list)->next)
		return ;
	first = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, first);
}

void	silent_rb(void)
{
	t_list	**list;
	t_list	*first;

	list = &get()->second;
	if (!list || !(*list) || !(*list)->next)
		return ;
	first = *list;
	*list = (*list)->next;
	ft_lstadd_back(list, first);
}

void	rr(void)
{
	silent_ra();
	silent_rb();
	get()->moves++;
	ft_printf("rr\n");
}

void	rrr(void)
{
	rra();
	rra();
	get()->moves++;
	ft_printf("rrr\n");
}

void	ss(void)
{
	sa();
	sb();
	get()->moves++;
	ft_printf("ss\n");
}
