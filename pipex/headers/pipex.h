/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:17:09 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/29 00:27:41 by rteles-f         ###   ########.fr       */
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
	int		id[2];
	int		fd[2];
	int		pipe[2];
	int		inter_pipe[2];
	char	**paths;
	char	***commands;
	char	**full_command;
} t_vars;

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
} t_pipex;

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
// void	free_commands(char ***commands);
// void	free_paths(char **paths);

// Pipex
void	pipex(t_vars *get, char *envp[]);
// void	child_process(t_vars *get);

#endif