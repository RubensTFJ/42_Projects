/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:28:08 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/23 15:11:00 by rteles-f         ###   ########.fr       */
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

void	free_split(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	if (!(*matrix))
	{
		free(matrix);
		ft_printf("Error\n");
		end_pushswap(get());
		return ;
	}
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	start_list(char **ascii_numbers, t_push *get)
{
	int	i;
	int	renumber;

	i = 0;
	while (ascii_numbers[i])
	{
		renumber = ft_atoi(ascii_numbers[i]);
		if (!ft_strcmp(sttc_itoa(renumber), ascii_numbers[i])
			&& !list_cointain(get->first, renumber))
			ft_lstadd_back(&get->first, ft_lstnew(renumber));
		else
		{
			ft_printf("Error\n");
			end_pushswap(get);
		}
		i++;
	}
	free_split(ascii_numbers);
	get->size = ft_lstsize(get->first);
}

int	main(int counter, char **input)
{
	(void)counter;
	while (++input && (*input))
		start_list(ft_split((*input), ' '), get());
	start_sort(get());
	print_push(get());
	end_pushswap(get());
	return (0);
}
