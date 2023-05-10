/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:36:54 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/10 21:17:56 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	private:
	std::string	name;
	Weapon		weapon;

	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon weapon);
		~HumanB();
		void	attack(void);
} ;

#endif