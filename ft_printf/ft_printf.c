/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:38:32 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/29 17:09:30 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list	var_sweep;
	int		i;
	int		printed;

	printed = 0;
	va_start(var_sweep, string);
	while (string && *string)
	{
		i = 0;
		while (string[i] && string[i] != '%')
			i++;
		printed += write (1, string, i);
		string += i;
		if (*string && *string++ == '%' && *string)
			printed += put_var(&var_sweep, (*string++));
	}
	va_end(var_sweep);
	return (printed);
}

int	put_var(va_list *arg_list, char var)
{
	if (var == 'i' || var == 'd')
		return ((int_case(va_arg(*arg_list, int))));
	if (var == 'c')
		return (char_case(va_arg(*arg_list, int)));
	if (var == 's')
		return (string_case(va_arg(*arg_list, char *)));
	if (var == 'u')
		return (put_base_number(va_arg(*arg_list, unsigned int), HEX, 10));
	if (var == 'x')
		return (put_base_number(va_arg(*arg_list, unsigned int), HEX, 16));
	if (var == 'X')
		return (put_base_number(va_arg(*arg_list, unsigned int), UPHEX, 16));
	if (var == 'p')
		return (pointer_case(va_arg(*arg_list, unsigned long)));
	if (var == '%')
		return (write (1, "%", 1));
	return (0);
}
