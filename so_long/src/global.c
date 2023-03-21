/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:42:49 by rteles-f          #+#    #+#             */
/*   Updated: 2023/02/27 18:04:46 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*on(int press)
{
	static char	keyboard[70000];

	return (&keyboard[press]);
}

t_list	**obj_list(void)
{
	static t_list	*ob;

	return (&ob);
}

t_infomap	*map(void)
{
	static t_infomap	inf;

	return (&inf);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
