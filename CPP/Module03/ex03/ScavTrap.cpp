/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:33:10 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/29 09:47:12 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:
		std::string	name;
		ClapTrap	test;
		int			gateMode = 0;

	public:
		ScavTrap(std::string name);
		~ScavTrap();
		void guardGate();
} ;

ScavTrap::ScavTrap(std::string name)
{}

ScavTrap::~ScavTrap()
{}

void	ScavTrap::guardGate(void)
{
	std::cout << this->name << " is on Guard Mode." << std::endl;
	gateMode = 1; 
}
