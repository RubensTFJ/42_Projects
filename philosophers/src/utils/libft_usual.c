/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_usual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 23:24:26 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/26 23:35:50 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*ft_calloc(size_t n, size_t xsize)
{
	char	*new;
	size_t	i;
	size_t	total;

	total = (n * xsize);
	new = malloc(total);
	if (!new)
		return (NULL);
	i = 0;
	while (i < total)
		new[i++] = 0;
	return (new);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	while ((8 < nptr[i] && nptr[i] < 14) || nptr[i] == 32)
		i++;
	sign = (nptr[i] != '-') - (nptr[i] == '-');
	i += (nptr[i] == '-' || nptr[i] == '+');
	number = 0;
	while (47 < nptr[i] && nptr[i] < 58)
		number = (nptr[i++] - 48) + (number * 10);
	return ((int)(number * sign));
}

void	watch_sleep(t_ulong time, t_philo *philo)
{
	t_ulong	start;

	start = get_time();
	while ((get_time() - start) < time
		&& philo->alive(philo))
		usleep(150);
}
