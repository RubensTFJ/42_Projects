/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:43 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/05 20:36:56 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Contact::table_print(std::string string) {
	int i = 0;
	while (string[i] && i < 8)
		std::cout << string[i++];
	if (string[i] && i == 8)
		std::cout << '.';
	else
	{
		while (i++ <= 8)
			std::cout << " ";	
	}
}

void	Contact::Update(std::string secret, std::string number,
			std::string nickname, std::string last_name, std::string name) {
	this->name = name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->secret = secret;
	this->number = number;
}

void	Contact::MiniPrint(int index) {
	std::cout << " " << index << "        ";
	std::cout << "| ";
	table_print(name);
	std::cout << "| ";
	table_print(last_name);
	std::cout << "| ";
	table_print(nickname);
	std::cout << std::endl;
}

void	Contact::FullPrint(void) {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Darkest Secret: " << secret << std::endl;
	std::cout << "Phone Number: " << number << std::endl;
}
