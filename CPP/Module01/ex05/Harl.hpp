/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:56:38 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/15 17:58:08 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <map>

class Harl {
	private:
		static void debug(void);
		static void info(void);
		static void warning(void);
		static void error(void);
		std::map<std::string, void(*)(void)> functions;

	public:
		Harl();
		~Harl();
		void complain(std::string level);
} ;

#endif