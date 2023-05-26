/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:02 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/26 20:55:01 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					fixed;
		static const int	fractional = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &obj);
		Fixed &operator= (const Fixed &obj);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
} ;

std::ostream& operator<<(std::ostream& stream, const Fixed& obj);

#endif
