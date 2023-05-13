/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:43:18 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/13 01:01:08 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	input_check(int counter, char **input, std::ifstream& in, std::ofstream& out)
{
	std::string		file;

	if (counter != 4 || !input[2] || !input[3])
	{
		std::cout << "Wrong Usage." << std:: endl;
		return (0);
	}
	file = input[1];
	file.append(".replace");
	in.open(input[1]);
	out.open(file);
	if (!in.is_open() || !out.is_open())
	{
		std::cout << "Failed to Open File." << std::endl;
		return (0);
	}
	return (1);
}

void	write_replace(std::ifstream& in, std::ofstream& out, std::string s1, std::string s2)
{
	std::string	line;
	std::size_t	found;

	while (getline(in, line))
	{
		while ((found = line.find(s1)) != std::string::npos)
		{
			line.erase(found, s1.length());
			line.insert(found, s2);
		}
		if (!in.eof())
			line += '\n';
		out.write(line.c_str(), line.length());
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	in;
	std::ofstream	out;

	if (!input_check(argc, argv, in, out))
		return (1);
	write_replace(in, out, argv[2], argv[3]);
	in.close();
	out.close();
	
	return (0);
}