/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:24:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/20 16:16:25 by rteles-f         ###   ########.fr       */
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

struct s_push {
	t_list	*first;
	t_list	*second;
	int		size;
	int		middle_value;
	int		moves;
	int		last_bit;
};

//Pushswap_utils
t_push	*get(void);
void	print_push(t_push *get);
void	end_pushswap(t_push *get);
void	free_list(t_list *list);

// Moves_a
void    sa(void);
void	pa(void);
void	ra(void);
void	rra(void);

// Moves_b
void    sb(void);
void	pb(void);
void	rb(void);
void	rrb(void);

// Moves_both
void	rr(void);
void	rrr(void);
void	ss(void);

// list
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

// Libft
void	*ft_calloc(size_t n, size_t xsize);
int		ft_strcmp(const char *s1, const char *s2);
char	*sttc_itoa(int number);
int		ft_atoi(const char *nptr);

void    start_sort(t_push *get);
void    small_sort(t_push *get);
void	radix(t_push *get);
void	last_bit(t_list *list);
int		count_wins(t_list *list, int value);

// list of 3 > 3 max.
// list of 5 > 12 max.
// list of 100 > 1100 max.

/*
3 1 2 - rra, sa

2 3 1 - sa - X
2 1 3 - rra - X
1 3 2 - ra - X
1 2 3 - sa, rra - X
3 2 1 - na - X


1 2 3 - na
1 3 2 - rra, sa
2 1 3 - sa
2 3 1 - rra
3 1 2 - ra
3 2 1 - sa, rra
*/

// ./push_swap 3 1 2 | ./checker_linux 3 1 2 &&
// ./push_swap 2 3 1 | ./checker_linux 2 3 1 &&
// ./push_swap 2 1 3 | ./checker_linux 2 1 3 &&
// ./push_swap 1 3 2 | ./checker_linux 1 3 2 &&
// ./push_swap 1 2 3 | ./checker_linux 1 2 3 &&
// ./push_swap 3 2 1 | ./checker_linux 3 2 1

#endif