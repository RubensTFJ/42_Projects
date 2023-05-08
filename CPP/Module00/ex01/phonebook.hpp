/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:48:49 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/05 20:35:04 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

class Contact {
	private:
		std::string	name;
		std::string	last_name;
		std::string	nickname;
		std::string	secret;
		std::string	number;

		void	table_print(std::string string);

	public:
		void	Update(std::string secret, std::string number,
			std::string nickname, std::string last_name, std::string name);
		void	MiniPrint(int index);
		void	FullPrint(void);
} ;

class PhoneBook {
	private:
		int		keeper = 0;
		Contact	*contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
		void	Add(void);
		void	Search(void);
		void	Exit(void);
} ;

std::string	ask_input(const char *string);

#endif