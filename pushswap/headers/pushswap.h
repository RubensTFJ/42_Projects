/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:24:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/15 03:28:24 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <ft_printf.h>

# define DEBUG1 write(1, "here\n", 5);
# define DEBUG2 write(1, "there\n", 6);

typedef struct s_list t_list;
typedef struct s_stack t_stack;
typedef struct s_push t_push;

struct	s_list {
	int		content;
	t_list	*next;
};

struct	s_stack {
	t_list	*head;
	int		size;
};

struct s_push {
	t_stack	first;
	t_stack	second;
};

// Libft
void	*ft_calloc(size_t n, size_t xsize);
int		ft_strcmp(const char *s1, const char *s2);
char	*sttc_itoa(int number);
int		ft_atoi(const char *nptr);

// list
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

// Moves_a
void    sa(t_list *list);
void	pa(t_push *get);
void	ra(t_list **list);
void	rra(t_stack *stack);

// Moves_b
void    sb(t_list *list);
void	pb(t_push *get);
void	rb(t_list **list);
void	rrb(t_stack *stack);

// Moves_both
void	rr(t_push *get);
void	rrr(t_push *get);
void	ss(t_push *get);

int		*moves(void);

// 1 2 3
// 1 3 2  ra sa rra
// 2 1 3  sa
// 2 3 1  rra
// 3 2 1  sa rra
// 3 1 2  ra 


#endif