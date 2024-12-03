/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:39:08 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/02 23:12:24 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed(const int n);
		Fixed(const float n);
		Fixed& operator=(const Fixed &other);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					m_n;
		static const int	m_fractBits = 8;
};

std::ostream& operator<<(std::ostream &stream, const Fixed &fixed);

#endif