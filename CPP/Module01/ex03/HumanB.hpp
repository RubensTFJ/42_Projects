/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:36:54 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/12 21:33:27 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	private:
	std::string	name;
	Weapon		*weapon;

	public:
		HumanB(std::string name);
		HumanB();
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon& weapon);
} ;

#endif