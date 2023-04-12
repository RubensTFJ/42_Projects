/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:36:39 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/12 20:54:51 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <ft_printf.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_talk
{
	int		size;
	int		bit;
	int		sent;
	char	*string;
} t_talk;

// Libft
int		ft_strlen(const char *string);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t n, size_t xsize);

#endif