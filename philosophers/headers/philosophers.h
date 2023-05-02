/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:07:27 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/02 22:06:37 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <ft_printf.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define DEAD 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define TAKE_FORK 4
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
	int	**forks;
	int	turn;
} ;

struct s_philo {
	int			id;
	int			last_eat;
	int			eat_times;
	int			status;
	int			wait;
	int			*right;
	int			*left;
	void		(*eat)(t_philo *philo);
	void		(*death)(t_philo *philo);
	int			(*turn)(t_philo *philo);
	void		(*sleep)(t_philo *philo);
	void		(*think)(t_philo *philo);
	t_control	*info;
} ;

struct s_fork {
	int				fork;
	pthread_mutex_t	*lock;
} ;

// Philo_actions
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);


// Libft
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *string);
void	*ft_calloc(size_t n, size_t xsize);
int		ft_atoi(const char *nptr);

#endif