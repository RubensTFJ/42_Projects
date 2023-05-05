/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:07:27 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/05 12:44:46 by rteles-f         ###   ########.fr       */
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

# define HERE write(1, "here\n", 5)
# define THERE write(1, "there\n", 6)

typedef unsigned long		t_ulong;
typedef struct s_control	t_control;
typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;

struct s_control {
	int			total;
	int			last_meal;
	int			turn;
	t_ulong		death_timer;
	t_ulong		watch;
	t_ulong		eat_timer;
	t_ulong		sleep_timer;
	t_philo		**philosophers;
	t_fork		**forks;
	pthread_t	joiner;
} ;

struct s_philo {
	int			id;
	int			eat_times;
	int			status;
	int			wait;
	t_ulong		last_eat;
	void		(*eat)(t_philo *philo);
	int			(*alive)(t_philo *philo);
	int			(*turn)(t_philo *philo);
	void		(*sleep)(t_philo *philo);
	void		(*think)(t_philo *philo);
	pthread_t	thread;
	t_control	*table;
} ;

struct s_fork {
	int				fork;
	pthread_mutex_t	lock;
} ;

// Main
void	check_start(t_control *get, int counter, char **input);
void	put_philosophers_on_table(t_control *get);
void	serve_forks(t_control *get);
void	thread_joiner(t_control *get);

// Philo_actions
void	ft_usleep(t_philo *philo, t_ulong time);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);
void	*table_manners(void *arg);

// Pactions_aux
void	take_fork(t_fork *get, t_philo *philo);
void	release_fork(t_fork *get);
int		ft_message(int type, t_philo *philo);
int		is_philo_alive(t_philo *philo);
int		is_turn(t_philo *philo);

// End_philosophers
void	end_dinner(char *string, t_control *get);
void	destroy_mutex(t_fork **forks, int size);
void	free_biarray(void **arg, int size);
t_philo	*new_philosopher(t_control *get, int id);
t_ulong	get_time(void);

// Libft
void	*ft_calloc(size_t n, size_t xsize);
int		ft_atoi(const char *nptr);

#endif