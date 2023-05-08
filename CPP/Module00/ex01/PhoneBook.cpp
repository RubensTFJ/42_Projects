/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:54:11 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/05 20:33:02 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(){
	for (int i = 0; i < 8; i++)
		contacts[i] = 0;
}

PhoneBook::~PhoneBook(){
	for (int i = 0; contacts[i]; i++)
		delete contacts[i];
}

void	PhoneBook::Add(void) 
{
	if (!contacts[keeper])
		contacts[keeper] = new Contact();
	contacts[keeper]->Update(ask_input("Enter Dark Secret: "), ask_input("Enter Phone Number: "),
			ask_input("Enter Nickname: "), ask_input("Enter Last Name: "), ask_input("Enter First Name: "));
	keeper++;
	if (keeper > 7)
		keeper = 0;
}

void	PhoneBook::Search(void)
{
	for (int i = 0; contacts[i]; i++)
		contacts[i]->MiniPrint(i);
	int	index = atoi(ask_input("Enter Desired Contact: ").c_str());
	if (-1 < index && index < 8 && contacts[index])
		contacts[index]->FullPrint();
	else
		std::cout << "Invalid Index." << std::endl;
}

void	PhoneBook::Exit(void) 
{
}
