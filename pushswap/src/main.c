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

int	main(int counter, char **input)
{
	(void)counter;
	start_list((input + 1), get());
	start_sort(get());
	end_pushswap(get());
	return (0);
}
