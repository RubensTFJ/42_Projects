/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:36:33 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/12 21:33:41 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{}

HumanB::~HumanB()
{}

HumanB::HumanB(std::string name):
name(name), weapon(NULL)
{}

void	HumanB::setWeapon(Weapon& weapon){
	this->weapon = &weapon;
}

void	HumanB::attack(void){
	std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}