/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:29:46 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/26 21:00:59 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixed(0) {
	std::cout << "Default Constructor Called." << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor Called." << std::endl;
}

Fixed &Fixed::operator= (const Fixed &obj) {
    std::cout << "Copy Assignment Operator Called." << std::endl;
	this->fixed = obj.getRawBits();

	return (*this);
}

Fixed::Fixed(const int n): fixed(n << fractional) {
    std::cout << "Int Constructor Called." << std::endl;
}

Fixed::Fixed(const float n): fixed(std::roundf(n * (1 << fractional))) {
    std::cout << "Float Constructor Called." << std::endl;
}

int	Fixed::getRawBits(void) const{
	return (this->fixed);
}

void Fixed::setRawBits(int const raw) {
	this->fixed = raw;
}

Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

float	Fixed::toFloat(void) const {
    return (static_cast<float>(this->getRawBits()) / (1 << fractional));
}

int	Fixed::toInt(void) const {
    return this->fixed >> fractional;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& obj) {
    stream << obj.toFloat();
    return stream;
}