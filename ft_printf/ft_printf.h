/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:19:08 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/26 20:25:01 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>

typedef unsigned long long	t_ull;

# define HEX "0123456789abcdef"
# define UPHEX "0123456789ABCDEF"

int	ft_printf(const char *string, ...);
int	put_var(va_list *arg_list, char var);
int	int_case(long long number);
int	pointer_case(size_t number);
int	char_case(int c);
int	string_case(char *string);
int	put_base_number(t_ull n, char *base, t_ull bsize);

#endif