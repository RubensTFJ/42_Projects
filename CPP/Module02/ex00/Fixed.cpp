/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:29:46 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/23 15:37:53 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixed(0) {
	std::cout << "Default Constructor Called." << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor Called." << std::endl;
}

Fixed &Fixed::operator= (const Fixed &obj){
    std::cout << "Copy Assignment Operator Called." << std::endl;
	this->fixed = obj.getRawBits();

	return (*this);
}

int	Fixed::getRawBits(void) const{
	return (this->fixed);
}

void Fixed::setRawBits(int const raw) {
	this->fixed = raw;
}