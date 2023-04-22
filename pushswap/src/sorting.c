/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:56:46 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/20 16:07:03 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	middle_value(t_list *list, int half)
{
	t_list  *start;
	int	    value;

	start = list;
	while (list)
	{
		if (count_wins(start, list->content) == half)
			value = list->content;
		list = list->next;
	}
	return (value);
}

void    fix_three(t_list *list)
{
	int	num[3];

	num[0] = list->content;
	num[1] = list->next->content;
	num[2] = list->next->next->content;
	if (num[0] > num[1] && num[1] > num [2])
		return ;
	else if (num[0] < num[1] && num[1] < num[2])
	{
		sa();
		rra();
	}
	else if (num[0] < num[1] && num[0] < num[2] && num[1] > num[2])
		ra();
	else if (num[0] > num[1] && num[1] < num[2] && num[2] > num[0])
		rra();
	else if (num[2] < num[0] && num[2] < num[1] && num[1] > num[2])
		sa();
	else if (num[0] > num[1] && num[0] > num[2] && num[1] < num[2])
	{
		rra();
		sa();
	}
}

int	list_bigger(t_list *list)
{
	int	save;

	save = 0;
	while (list)
	{
		if (list->content > save)
			save = list->content;
		list = list->next;
	}
	return (save);
}

int	list_smaller(t_list *list)
{
	int	save;

	save = get()->size;
	while (list)
	{
		if (list->content < save)
			save = list->content;
		list = list->next;
	}
	return (save);
}

int	find_position(t_list *list, int number)
{
	int	position;
	int	min;
	int	max;
	int	size;

	size = ft_lstsize(list);
	min = list_smaller(list);
	max = list_bigger(list);
	position = 0;
	if (number < min || number > max)
	{
		while (list->content != max)
		{
			list = list->next;
			position++;
		}
	}
	else
	{
		while (!(number > list->content
			&& number < ft_lstlast(list)->content))
		{
			list = list->next;
			position++;
		}
	}
	return (position);
}

void	ma(t_push *get)
{
	while (get->second)
	{
		if (get->second->content == 1)
		{
			while (get->first->content != get)
		}
		else if (get->second->content == get->size)
		{
			while (get->first->content != (get->size - 1))
				ra();
			pa();
		}
		else
		{
			while (!(get->second->content > get->first->content
				&& get->second->content < ft_lstlast(get->first)->content))
				ra();
			pa();
		}
	}
}

void	ma(t_push *get)
{
	while (get->second)
	{
		while (!(get->second > get->first && get->second < ft_lstlast(get->first)->content))
		if (get->second->content > get->first->content)
			pa();
		else if (get->second->content < get->first->content
			&& get->second->content < list_smaller(get->first))
		{
			pa();
			rra();
		}
		else
		{
			while (get->second->content < get->first->content)
				ra();
			pa();
		}
	}
	while (get->first->content != get->size)
			ra();			
}

void    small_sort(t_push *get)
{
	int	push;
	push = get->size - 3;
	while (push)
	{
		pb();
		push--;
	}
	fix_three(get->first);
	if (get->second && get->second->next
		&& get->second->content < get->second->next->content)
		sb();
	print_push(get);
	if (get->second)
		ma(get);
}

void	radix(t_push *get)
{
	int i;
	int pos;

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


void	start_sort(t_push *get)
{
	if (get->size < 6)
		small_sort(get);
	else
		radix(get);
}