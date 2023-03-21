/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:20:38 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/20 18:58:33 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;		

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = number * (-1);
	}
	if (number > 9)
		ft_putnbr_fd((number / 10), fd);
	ft_putchar_fd("0123456789"[number % 10], fd);
}
