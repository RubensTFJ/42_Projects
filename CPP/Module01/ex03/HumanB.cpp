/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:36:33 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/10 21:17:50 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	Weapon w = Weapon("Hands");
	this->name = name;
	this->weapon = w;
}

HumanB::HumanB(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanB::~HumanB()
{}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}