/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:06:51 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/03 15:06:51 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define C (char)

int	reset(int *var)
{
	var[1] = 1;
	return (0);
}

int	set(int *var, int value)
{
	var[0] = value;
	var[1] = 0;
	return (1);
}

int	main(void)
{
	int	i[2];
	
	while ((!i[1] || set(i, -1)) && ++i[0] < 10)
	{
			printf("I: %i, J: %i\n", i[0], j[0]);
	}
}


<<<<<<< HEAD
int set(int *var, int value)
=======
int	set(int *var, int value)
>>>>>>> refs/remotes/origin/main
{
	*var = value;
	*var |= (1 << 30);
	return (1);
}

int	main(void)
{
	int	i;
	int	j;

	printf("%i\n", (1 << 30));
	while ((i++ & (1 << 30) || set(&i, 0)) && (char)i < 10)
	{

	}
}
