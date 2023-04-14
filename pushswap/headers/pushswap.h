/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:24:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/14 23:33:10 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ft_printf.h>

typedef struct s_push {
	t_stack	first;
	t_stack	second;
} t_push;

typedef struct	s_stack {
	t_list	*head;
	int		size;
} t_stack;

typedef struct	s_list {
	int		content;
	t_list	*next;
} t_list;

// Libft
void	*ft_calloc(size_t n, size_t xsize);
int		ft_strcmp(const char *s1, const char *s2);
char	*sttc_itoa(int number);
int		ft_atoi(const char *nptr);

// list
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);

// Moves_a
void    sa(t_list *list);
void	pa(t_push *get);
void	ra(t_list *list);
void	rra(t_stack *stack);

// Moves_b
void    sb(t_list *list);
void	pb(t_push *get);
void	rb(t_list *list);
void	rrb(t_stack *stack);

// Moves_both
void	rr(t_push *get);
void	rrr(t_push *get);
void	ss(t_push *get);

#endif