/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:12:38 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/23 10:16:43 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

t_push	*get(void)
{
	static t_push	get;

	return (&get);
}

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}

void	end_pushswap(t_push *get)
{
	if (get->first)
		free_list(get->first);
	if (get->second)
		free_list(get->second);
	exit(0);
}

void	print_push(t_push *get)
{
	t_list	*first;
	t_list	*second;
	int		n[2];

	first = get->first;
	second = get->second;
	while (first || second)
	{
		if (first)
			n[0] = first->content;
		else
			n[0] = 0;
		if (second)
			n[1] = second->content;
		else
			n[1] = 0;
		ft_printf("%i, %i\n", n[0], n[1]);
		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}
	ft_printf("f, s\n\n\n");
}
