/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:07:27 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/29 03:27:54 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <ft_printf.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define DEAD 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define LEFT -1
# define MY 0
# define RIGHT +1

typedef struct s_control	t_control;
typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;

struct s_control {
	int	total;
	int	death_timer;
	int	eat_timer;
	int	sleep_timer;
	int	last_meal;
} ;

struct s_philo {
	int		id;
	int		last_eat;
	int		eat_times;
	int		status;
	t_philo	*right;
	t_philo	*left;
	t_fork	*fork;
	t_fork	*borrow;
} ;

struct s_fork {
	t_philo	*owner;
	t_philo	*holder;
} ;

// Libft
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *string);
void	*ft_calloc(size_t n, size_t xsize);

#endif