/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:57:27 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/05 19:57:27 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	ask_input(const char *string) {
	std::string	input;

	input.clear();
	while (input.empty())
	{
		std::cout << string << std::endl;
		getline(std::cin, input);
		if (input.empty())
			std::cout << "Invalid Input." << std::endl;
	}
	return (input);
}

void	str_tolower(std::string	string)
{
	for (char& c : string)
		c = tolower(c);
}

int	main(int counter, char **input)
{
	PhoneBook	book;
	std::string	command;

	while (true)
	{
		std::cout << "Enter Command: " << std::endl;
		getline(std::cin, command);
		str_tolower(command);
		if (command == "add")
			book.Add();
		else if (command == "search")
			book.Search();
		else if (command == "exit")
		{
			book.Exit();
			return (0);
		}
		else
			std::cout << "Wrong Usage. Valid commands: 'ADD', 'SEARCH' and 'EXIT'" << std::endl;
	}
}
