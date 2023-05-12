/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:08:09 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/12 21:34:14 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA()
{}

HumanA::HumanA(std::string name, Weapon&  weapon):
name(name), weapon(weapon)
{}

void	HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}