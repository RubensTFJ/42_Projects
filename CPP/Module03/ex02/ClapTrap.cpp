/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:14:10 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/29 09:53:55 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
	name(name), hitPoints(100), energyPoints(50), attackDamage(20)
{}

ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage):
	name(name), hitPoints(hitPoints), energyPoints(energyPoints), attackDamage(attackDamage)
{}

ClapTrap::~ClapTrap() {
	std::cout << this->name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << this->name << " Attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << this->name << " took " << amount << " Damage!" << std::endl;
	this->hitPoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << this->name << " Gained " << amount << " Points!" << std::endl;
	this->hitPoints += amount;
} ;
