/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_usual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:44:31 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/02 15:20:45 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_stradd(char **original, char *add)
{
	int		i;
	int		j;
	char	*joined;

	if (!(*original) || !add)
		return (NULL);
	joined = ft_calloc(sizeof(char),
			(ft_strlen((*original)) + ft_strlen(add) + 1));
	if (!joined)
		return (NULL);
	i = -1;
	while ((*original)[++i])
		joined[i] = (*original)[i];
	j = -1;
	while (add[++j])
		joined[i + j] = add[j];
	free((*original));
	*original = joined;
	return (joined);
}

char	*sttc_itoa(int number)
{
	static char	to_ascii[12];
	int			index;
	int			sign;

	sign = (number > 0) - (number < 0);
	index = 11;
	while (number || index == 11)
	{
		to_ascii[--index] = (number % 10) * sign + '0';
		number = number / 10;
	}
	if (sign < 0)
		to_ascii[--index] = '-';
	return (&to_ascii[index]);
}

void	free_biarray(void **arg, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(arg[i++]);
	free(arg);
}
