/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:36:38 by rteles-f          #+#    #+#             */
/*   Updated: 2022/10/27 19:08:02 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argument)
{
	if ((64 < argument && argument < 91)
		|| (96 < argument && argument < 123)
		|| (47 < argument && argument < 58))
	{
		return (1);
	}
	return (0);
}
