/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:33:10 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/26 21:44:58 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap {
	private:
		ClapTrap test;

	public:
		ScavTrap(std::string name);
		~ScavTrap();
} ;

ScavTrap::ScavTrap(std::string name):
	test(name, 100, 50, 20)
{}