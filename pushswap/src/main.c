/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:28:08 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/20 16:59:15 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	list_cointain(t_list *list, int check)
{
	while (list)
	{
		if (list->content == check)
			return (1);
		list = list->next;
	}
	return (0);
}

void	start_list(char **ascii_numbers, t_push *get)
{
	int	i;
	int	renumber;

	i = -1;
	while (ascii_numbers[++i])
	{
		renumber = ft_atoi(ascii_numbers[i]);
		if (!ft_strcmp(sttc_itoa(renumber), ascii_numbers[i])
			&& !list_cointain(get->first, renumber))
			ft_lstadd_back(&get->first, ft_lstnew(renumber));
		else
		{
			ft_printf("Wrong input: %i#: %s\n", (i + 1), ascii_numbers[i]);
			end_pushswap(get);
		}
	}
	get->size = ft_lstsize(get->first);
}

int	count_wins(t_list *list, int value)
{
	int	wins;

	wins = 0;
	while (list)
	{
		if (value > list->content)
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

int	main(int counter, char **input)
{
	(void)counter;
	start_list((input + 1), get());
	rescale(&get()->first);
	print_push(get());
	last_bit(get()->first);
	start_sort(get());
	// radix(get());
	print_push(get());
	ft_printf("(Moves: %i), Middle_value: %i\n", get()->moves, get()->middle_value);
	end_pushswap(get());
	return (0);
}
