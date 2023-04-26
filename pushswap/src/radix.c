/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:16:59 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/23 10:16:59 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

void	last_bit(t_list *list)
{
	int	pos;
	int	last_bit;

	last_bit = 0;
	while (list)
	{
		pos = 0;
		while (pos < 32)
		{
			if (list->content & (1 << pos) && pos > last_bit)
				last_bit = pos;
			pos++;
		}
		list = list->next;
	}
	get()->last_bit = last_bit;
}

int	count_wins(t_list *list, int value)
{
	int	wins;

	wins = 0;
	while (list)
	{
		if (value >= list->content)
			wins++;
		list = list->next;
	}
	return (wins);
}

void	rescale(t_list **list)
{
	t_list	*iterate;
	t_list	*new;

	new = NULL;
	iterate = *list;
	while (iterate)
	{
		ft_lstadd_back(&new, ft_lstnew(get()->size
				- count_wins((*list), iterate->content)));
		iterate = iterate->next;
	}
	free_list((*list));
	*list = new;
}

void	radix(t_push *get)
{
	int	i;
	int	pos;

	pos = 0;
	while (pos <= get->last_bit)
	{
		i = 0;
		while (i < get->size)
		{
			if (get->first->content & (1 << pos))
				pb();
			else
				ra();
			i++;
		}
		while (get->second)
			pa();
		pos++;
	}
}
