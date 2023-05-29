/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:16:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/29 10:19:01 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"

class DiamonTrap: public ClapTrap, public ScavTrap {
	private:
		std::string name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		DiamonTrap();
		DiamonTrap(std::string name);
		~DiamonTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
} ;

#endif