/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:05:03 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/23 15:30:11 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>





/*
Ad-hoc polymorphism, operator overloading
and Orthodox Canonical class form
Create a class in Orthodox Canonical Form that represents a fixed-point number:
• Private members:
	◦ An integer to store the fixed-point number value.
	◦ A static constant integer to store the number of fractional bits. Its value
	will always be the integer literal 8.
• Public members:
	◦ A default constructor that initializes the fixed-point number value to 0.
	◦ A copy constructor.
	◦ A copy assignment operator overload.
	◦ A destructor.
	◦ A member function int getRawBits( void ) const;
	that returns the raw value of the fixed-point value.
	◦ A member function void setRawBits( int const raw );
	that sets the raw value of the fixed-point number.
*/