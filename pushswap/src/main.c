/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:28:08 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/15 03:35:57 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

int	*moves(void)
{
	static int	counter;

	return (&counter);
}

void	print_push(t_push *get)
{
	t_list	*first;
	t_list	*second;
	int		n[2];

	first = get->first.head;
	second = get->second.head;
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

void	free_list(t_list *list)
{
	t_list *temp;

	while(list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}

void	end_pushswap(t_push *get)
{
	if (get->first.head)
		free_list(get->first.head);
	if (get->second.head)
		free_list(get->second.head);
	exit(1);
}

int	ft_str_isdigit(char *argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		if (argument[i] < 47 || argument[i] > 58)
			return (0);
		i++;
	}
	return (1);
}

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

void	start_list(char **ascii_numbers, t_stack *stack, t_push *get)
{
	int	i;

	i = -1;
	while (ascii_numbers[++i])
	{
		if (!ft_strcmp(sttc_itoa(ft_atoi(ascii_numbers[i])), ascii_numbers[i])
			&& ft_str_isdigit(ascii_numbers[i])
				&& !list_cointain(stack->head, ft_atoi(ascii_numbers[i])))
			ft_lstadd_back(&stack->head, ft_lstnew(ft_atoi(ascii_numbers[i])));
		else
		{
			ft_printf("Wrong input: %s\n", ascii_numbers[i]);
			end_pushswap(get);
		}
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

void	next_pair(t_list *first, t_list *second)
{
	if (first->content > first->next->content)
		sa(first);
	if (second->content > second->next->content)
		sa(second);
}

void	pair_organize(t_stack *stack)
{
	int		go;

	go = stack->size / 2;
	while (go > -2)
	{
		if (stack->head->content > stack->head->next->content)
		{
			sa(stack->head);
			ra(&stack->head);
			ra(&stack->head);
		}
		if (!check_pairs(stack->head))
			go -= 2;
		else
			go = -2;
	}
}

void	divide_list(t_stack *first, t_stack *second, t_push *get)
{
	int	go;

	go = first->size / 2;
	while (go > 0)
	{
		if (first->head->content < first->head->next->content)
			sa(first->head);
		pb(get);
		pb(get);
		go -= 2;
	}
	first->size = ft_lstsize(first->head);
	second->size = ft_lstsize(second->head);
	pair_organize(&get->first);
}

void	orgnize_three(t_push *get)
{
	t_list	*list;

	list = get->first.head;
	if (list->content > list->next->next->content)
		ra(&get->first.head);
}

void	ma(t_push *get)
{
	if (get->second.head)
	{
		print_push(get);
		if (get->second.head->content < get->first.head->content)
		{
			pa(get);
			ma(get);
		}
		else if (get->second.head->content > ft_lstlast(get->first.head)->content)
		{
			pa(get);
			ra(&get->first.head);
			ma(get);
		}
		else
		{
			rra(&get->first);
			ma(get);
			ra(&get->first.head);
		}
	}
}

void	adapt_merge(t_push *get)
{
	divide_list(&get->first, &get->second, get);
	orgnize_three(get);
	ma(get);
}

int	main(int counter, char **input)
{
	static t_push	get;

	(void)counter;
	start_list((input + 1), &get.first, &get);
	// print_push(&get);
	adapt_merge(&get);
	print_push(&get);
	ft_printf("((%i))\n", *moves());
	end_pushswap(&get);
	return (0);
}

/*
int	*moves(void)
{
	static int	counter;

	return (&counter);
}

void	print_push(t_push *get)
{
	t_list	*first;
	t_list	*second;
	int		n[2];

	first = get->first.head;
	second = get->second.head;
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

void	free_list(t_list *list)
{
	t_list *temp;

	while(list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}

void	end_pushswap(t_push *get)
{
	if (get->first.head)
		free_list(get->first.head);
	if (get->second.head)
		free_list(get->second.head);
	exit(1);
}

int	ft_str_isdigit(char *argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		if (argument[i] < 47 || argument[i] > 58)
			return (0);
		i++;
	}
	return (1);
}

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

void	start_list(char **ascii_numbers, t_stack *stack, t_push *get)
{
	int	i;

	i = -1;
	while (ascii_numbers[++i])
	{
		if (!ft_strcmp(sttc_itoa(ft_atoi(ascii_numbers[i])), ascii_numbers[i])
			&& ft_str_isdigit(ascii_numbers[i])
				&& !list_cointain(stack->head, ft_atoi(ascii_numbers[i])))
			ft_lstadd_back(&stack->head, ft_lstnew(ft_atoi(ascii_numbers[i])));
		else
		{
			ft_printf("Wrong input: %s\n", ascii_numbers[i]);
			end_pushswap(get);
		}
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

void	next_pair(t_list *first, t_list *second)
{
	if (first->content > first->next->content)
		sa(first);
	if (second->content > second->next->content)
		sa(second);
}

void	pair_organize(t_push *get)
{
	int		go;

	go = get->first.size / 2;
	while (go > -2)
	{
		next_pair(get->first.head, get->second.head);
		rr(get);
		rr(get);
		go -= 2;
	}
}

void	divide_list(t_stack *first, t_stack *second, t_push *get)
{
	int	go;

	go = first->size / 2;
	while (go > 0)
	{
		pb(get);
		pb(get);
		go -= 2;
	}
	first->size = ft_lstsize(first->head);
	second->size = ft_lstsize(second->head);
	pair_organize(get);
}

void	orgnize_three(t_push *get)
{
	t_list	*list;

	list = get->first.head;
	if (list->content > list->next->next->content)
		ra(&get->first.head);
	
}

void	adapt_merge(t_push *get)
{
	divide_list(&get->first, &get->second, get);
	orgnize_three(get);
}

int	main(int counter, char **input)
{
	static t_push	get;

	(void)counter;
	start_list((input + 1), &get.first, &get);
	// print_push(&get);
	adapt_merge(&get);
	print_push(&get);
	ft_printf("((%i))\n", *moves());
	end_pushswap(&get);
	return (0);
}
*/