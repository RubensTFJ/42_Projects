/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:43:18 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/12 21:57:50 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	input_check(int counter, char **input)
{
	if (counter != 3 || !input[1] || !input[2])
	{
		std::cout << "Wrong Usage." << std:: endl;
		return (0);
	}
	
}

int	main(int argc, char **argv)
{
	std::ifstream	in;
	std::ofstream	out;

	if (!input_check(argc, argv))
		return (1);
	in.open(argv[1]);
	out.open(argv[2]);
}