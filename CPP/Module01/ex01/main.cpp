/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:58:38 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/08 21:39:26 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	nzombies;

	nzombies = 10;
	Zombie	*horde = zombieHorde(nzombies, "foo");
	for (int i = 0; i < nzombies; i++)
	{
		horde[i].announce();
	}
	delete[] horde;

	return (0);
}