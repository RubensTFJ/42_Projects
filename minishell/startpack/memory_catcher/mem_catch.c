/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_catch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:24:58 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/09 13:41:09 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// #define malloc(x) ft_alloc_keep(x)

typedef struct s_list	t_list;

struct s_list {
	void	*content;
	t_list	*next;
} ;

static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iterate;

	if (!lst || !new)
		return ;
	iterate = *lst;
	if (iterate)
	{
		while (iterate->next != NULL)
			iterate = iterate->next;
		iterate->next = new;
	}
	else
		*lst = new;
}

static t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	return (newnode);
}

t_list	**mem_list(void)
{
	static t_list	*all;

	return (&all);
}

void	clear_alloc(void)
{
	t_list	*temp;
	t_list	*list;
	int		counter;

	counter = 0;
	list = *mem_list();
	while (list)
	{
		counter++;
		temp = list->next;
		if (list->content)
		{
			ft_printf("Leak! Alloc #%i\n", counter);
			free(list->content);
		}
		free(list);
		list = temp;
	}
}


void	*keep_alloc(size_t size)
{
	int				i;
	char			*alloc;

	alloc = malloc(size);
	i = 0;
	while (i < size)
		alloc[i++] = 0;
	ft_lstadd_back(mem_list(), ft_lstnew((void *)alloc));
	return (alloc);
}
