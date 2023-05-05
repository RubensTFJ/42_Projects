/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_catch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:24:58 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/05 16:06:23 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <philosophers.h>

typedef struct s_list	t_list;

struct s_list {
	void	*content;
	t_list	*next;
} ;

// static void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*iterate;

// 	if (!lst || !new)
// 		return ;
// 	iterate = *lst;
// 	if (iterate)
// 	{
// 		while (iterate->next != NULL)
// 			iterate = iterate->next;
// 		iterate->next = new;
// 	}
// 	else
// 		*lst = new;
// }

// static t_list	*ft_lstnew(void *content)
// {
// 	t_list	*newnode;

// 	newnode = ft_calloc(sizeof(t_list), 1);
// 	if (!newnode)
// 		return (NULL);
// 	newnode->content = content;
// 	return (newnode);
// }

static void	calloc_clear(t_list *list)
{
	t_list	*temp;

	while (list->next)
	{
		temp = list->next;
		if (list->content)
			free(list->content);
		free(list);
		list = temp;
	}
}

void	*calloc_keep(size_t type, size_t size)
{
	size_t			total;
	static t_list	*all;
	size_t			i;
	int				*alloc;

	if (!type || !size)
	{
		calloc_clear(all);
		return (0);
	}
	total = type * size;
	alloc = malloc(total);
	if (!alloc)
		return (0);
	i = 0;
	while (i < total)
		alloc[i++] = 0;
	// ft_lstadd_back(&all, ft_lstnew((void *)alloc));
	return (alloc);
}


