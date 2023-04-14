/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:28:08 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/14 23:36:14 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	ft_isdigit(int argument)
{
	if (47 < argument && argument < 58)
	{
		return (1);
	}
	return (0);
}

void	start_list(char *ascii_numbers, t_stack *stack)
{
	int	i;

	i = -1;
	while (ascii_numbers[++i])
	{
		if (!ft_strcmp(sttc_itoa(ft_atoi(ascii_numbers[i])), ascii_numbers[i])
			&& ft_isdigit(ascii_numbers[i]))
			ft_lstadd_back(stack->head, ft_lstnew(ft_atoi(ascii_numbers[i])));
		else
			end_pushswap("Invalid Output: %c\n", ascii_numbers[i]);
	}
	stack->size = ft_lstsize(stack->head);
}

int	check_pairs(t_list *list)
{
	t_list *iterate;

	iterate = list;
	while (iterate && iterate->next)
	{
		if (iterate->content > iterate->next->content)
			return (0);
		else
			iterate = iterate->next->next;
	}
	return (1);
}

void	pair_organize(t_stack *stack)
{
	int		go;

	go = stack->size / 2;
	while (go)
	{
		if (stack->head->content > stack->head->next->content)
			sa(stack->head);
		if (!check_pairs(stack->head))
		{
			ra(stack->head);
			ra(stack->head);
			go -= 2;
		}
		else
			go = 0;
	}
}

void	divide_list(t_stack *first, t_stack *second, t_push *get)
{
	int	go;

	go = first->size / 2;
	while (go)
	{
		if (first->head->content < first->head->next->content)
			sa(first->head);
		pb(get);
		pb(get);
		go -= 2;
	}
	first->size = ft_lstsize(first->head);
	second->size = ft_lstsize(second->head);
	pair_organize(first);
}

void	adapt_merge(t_push *get)
{
	divide_list(&get->first, &get->second, get);
}

int	main(int counter, char **input)
{
	static t_push	get;

	start_list(input[2], &get.first);
	adapt_merge(&get);
	end_pushswap(&get);
	return (0);
}
