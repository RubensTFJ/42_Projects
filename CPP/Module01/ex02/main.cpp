/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:44:30 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/08 21:57:54 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	hi = "HI THIS IS BRAIN";
	std::string	*pointer = &hi;
	std::string	&reference = hi;
	
	std::cout << "String Adress: " << &hi << std::endl;
	std::cout << "Pointer Content: " << pointer << std::endl;
	std::cout << "Reference Content: " << &reference << std::endl;

	std::cout << std::endl;

	std::cout << "String Value: " << hi << std::endl;
	std::cout << "Pointer Value: " << *pointer << std::endl;
	std::cout << "Reference Value: " << reference << std::endl;
}