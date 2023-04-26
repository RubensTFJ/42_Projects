/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:56:46 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/25 16:35:35 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	middle_value(t_list *list, int half)
{
	t_list	*start;
	int		value;

	start = list;
	while (list)
	{
		if (count_wins(start, list->content) == half)
			value = list->content;
		list = list->next;
	}
	return (value);
}

void	fix_three(t_list *list)
{
	int	num[3];

	num[0] = list->content;
	num[1] = list->next->content;
	num[2] = list->next->next->content;
	if (num[0] < num[1] && num[1] < num [2])
		return ;
	else if (num[0] > num[1] && num[1] > num[2])
	{
		sa();
		rra();
	}
	else if (num[0] > num[1] && num[0] > num[2] && num[1] < num[2])
		ra();
	else if (num[0] < num[1] && num[1] > num[2] && num[2] < num[0])
		rra();
	else if (num[2] > num[0] && num[2] > num[1] && num[1] < num[2])
		sa();
	else if (num[0] < num[1] && num[1] > num[2] && num[0] < num[2])
	{
		rra();
		sa();
	}
}

void	small_sort(t_push *get)
{
	int	middle;

	middle = middle_value(get->first, ((get->size / 2.f + 0.5)));
	while (ft_lstsize(get->first) > 3)
	{
		if (get->first->content < middle)
			pb();
		else
			ra();
	}
	if (ft_lstsize(get->first) == 3)
		fix_three(get->first);
	else if (get->first && get->first->next
		&& get->first->content > get->first->next->content)
		sa();
	if (get->second && get->second->next
		&& get->second->content < get->second->next->content)
		sb();
	while (get->second)
		pa();
}

int	is_sequence(t_list *list)
{
	while (list && list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

void	start_sort(t_push *get)
{
	if (is_sequence(get->first))
		return ;
	if (get->size < 6)
		small_sort(get);
	else
	{
		rescale(&get->first);
		last_bit(get->first);
		radix(get);
	}
}
