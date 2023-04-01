/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:36:39 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/01 00:18:24 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <ft_printf.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define LOOP 1

// Libft
int		ft_strlen(const char *string);
int		ft_atoi(const char *nptr);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t n, size_t xsize);

#endif