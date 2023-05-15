/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:44:21 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/15 17:11:23 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <ft_printf.h>
# define HERE write(1, "here\n", 5)
# define THERE write(1, "there\n", 6)

typedef struct s_control	t_control;
typedef struct s_list		t_list;
typedef struct s_shell		t_shell;
typedef struct s_command	t_command;
typedef void (*exe)();


struct s_control {
	int		argc;
	char	**argv;
	char	**envp;
	char	*line;
	char	find[7];
	char	*test[5];
	exe		functions[5];
	t_list	*commands;
} ;

struct s_list {
	exe		content;
	char	*type;
	t_list	*next;
} ;

struct s_command {
	char	*line;
	char	**split;
	int		input;
	int		output;
} ;

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *string);
void	*ft_calloc(size_t n, size_t xsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*sttc_itoa(int number);
char	*ft_itoa(int number);
void	free_biarray(void **arg, int size);

#endif