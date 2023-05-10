/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:41:12 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/10 21:31:35 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon()
{}

Weapon::~Weapon()
{}

std::string&	Weapon::getType(void)
{
	std::string&	get = this->type;

	return (get);
}

void	Weapon::setType(std::string type)
{
	getType() = type;
}
