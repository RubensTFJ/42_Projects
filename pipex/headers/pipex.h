/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:17:09 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/30 02:59:14 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <ft_printf.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_vars {
	int		id;
	int		fd[2];
	int		*pipe1;
	int		*pipe2;
	char	**envp;
	char	**paths;
	char	***commands;
	char	**full_command;
}	t_vars;

// Libft
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *string);
void	*ft_calloc(size_t n, size_t xsize);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);

// Main
int		get_commands(int size, t_vars *get, char **input);
int		get_paths(char **envp, t_vars *get);
void	finish_list_with(char **list, char *put);
void	check_start(int argc, char **argv, t_vars *get);

// End_Program
void	end_pipex(t_vars *get, int exit_type, char *string);
void	free_commands(char ***commands);
void	free_list(char **list);
void	finish_list_with(char **list, char *put);

// Pipex
void	pipex(t_vars *get);
void	executioner(t_vars *get, int *in_pipe, int *out_pipe, int index);

#endif