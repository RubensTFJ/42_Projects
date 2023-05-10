/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:07:27 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/10 18:32:35 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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

typedef unsigned long		t_ulong;
typedef struct s_control	t_control;
typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;
typedef pthread_mutex_t		t_mutex;

struct s_control {
	int			total;
	int			turn;
	int			service;
	int			last_meal;
	t_ulong		clock;
	t_philo		**philosophers;
	t_fork		**utensils;
	t_ulong		death_timer;
	t_ulong		eat_timer;
	t_ulong		sleep_timer;
	t_mutex		turn_lock;
	t_mutex		service_lock;
	pthread_t	joiner;
} ;

struct s_philo {
	int			id;
	int			eat_times;
	int			status;
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
int		check_start(t_control *get, int counter, char **input);
int		put_philosophers_on_table(t_control *get);
int		serve_utensils(t_control *get);
void	wait_dinner(t_control *get);

// Philo_actions
void	att_turn(t_control *get);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);
void	*table_manners(void *arg);

// Pactions_aux
void	take_fork(t_fork *get, t_philo *philo);
void	release_fork(t_fork *get);
int		ft_message(int type, t_philo *philo);
int		check_table(t_philo *philo);
int		is_turn(t_philo *philo);

// End_philosophers
int		end_dinner(char *string, t_control *get);
void	destroy_mutex(t_fork **utensils, int size);
void	free_biarray(void **arg, int size);
t_philo	*new_philosopher(t_control *get, int id);
t_ulong	get_time(void);

// Libft
void	watch_sleep(t_ulong time, t_philo *philo);
void	*ft_calloc(size_t n, size_t xsize);
int		ft_atoi(const char *nptr);

#endif

// 1 800 200 200 - morte
// 5 800 200 200 - n morre
// 5 800 200 200 7 - n morre
// 4 410 200 200 - n morre
// 4 310 200 100 - morre