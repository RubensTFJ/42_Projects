/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:44:21 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/05 19:24:12 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <signal.h>
# include <stdbool.h>
# define HERE write(1, "here\n", 5)
# define THERE write(1, "there\n", 6)


typedef struct s_control	t_control;
typedef struct s_func		t_func;
typedef struct s_shell		t_shell;
typedef struct s_command	t_command;
typedef struct sigaction	t_sigaction;
typedef void				(*t_exe)();


struct s_control {
	char		*input;
	char		**envp;
	char		**paths;
	char		***pieces;
	char		**separators;
	int			pipe[2];
	t_sigaction	siginfo;
	t_list		*commands;
} ;

typedef struct s_command {
	char		*exec_path;
	char		**flags;
	char		**terminal;
	char		*aux;
	int			id;
	int			instream;
	int			pipe[2];
	int			is_last;
	int			counter;
	int			valid;
	t_control	*main;
	t_exe		execute;
} t_command;

char	*sttc_itoa(int number);
void	free_biarray(void **arg, int size);
char	*ft_stradd(char **original, char *add);
char	**shell_split(char *s, char c);
void	free_split(char **arg);

void	normalize_input(t_control *get);
int		ignore_quotes(char *string);
void	free_shellsplit(char ***arg);

void	execve_aux(t_command *get);
void	setup(t_control *get, char **envp);
void	structure_commands(t_control *get);
void	run_input(t_list *node);




#endif