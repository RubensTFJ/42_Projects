/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:01:02 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/08 21:01:02 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
	std::string	name;
	int			del;

	public:
		Zombie();
		~Zombie();
		void	setName(std::string name);
		void	announce(void);
} ;

Zombie* zombieHorde( int N, std::string name );

#endif