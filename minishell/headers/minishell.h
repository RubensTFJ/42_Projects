/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:44:21 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/02 12:16:21 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libft.h> 
# define HERE write(1, "here\n", 5)
# define THERE write(1, "there\n", 6)

typedef struct s_control	t_control;
typedef struct s_func		t_func;
typedef struct s_shell		t_shell;
typedef struct s_command	t_command;
typedef void (*exe)();

struct s_control {
	char	*input;
	char	**split;
	char	**envp;
	char	**paths;
	char	***pieces;
	char	**separators;
	int		pipe[2];
	t_list	*commands;
} ;

struct s_func {
	exe		pointer;
	char	*type;
} ;

struct s_command {
	char	*path;
	char	**command;
	int		input;
	int		output;
} ;

char	*sttc_itoa(int number);
void	free_biarray(void **arg, int size);
char	*ft_stradd(char **original, char *add);
char	**shell_split(char *s, char c);
void	free_split(char **arg);

#endif