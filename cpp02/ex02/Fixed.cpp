/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:24:47 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/07 10:46:16 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : m_n(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n) : m_n(n << m_fractBits)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : m_n(static_cast<int>(n * (1 << m_fractBits) + (n >= 0 ? 0.5f : -0.5f)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->m_n = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->m_n;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->m_n = raw;
}

int	Fixed::toInt(void) const
{
	return this->m_n >> this->m_fractBits;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(this->m_n) / (1 << this->m_fractBits);
}

std::ostream& operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return stream;
}

/********* Comparision operator overload **********/
bool	Fixed::operator>(const Fixed &other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool	Fixed::operator<(const Fixed &other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed &other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return this->getRawBits() != other.getRawBits();
}

/*********** Arithmetic operator overload ************/
Fixed Fixed::operator+(const Fixed &other) const
{
	float ans = this->toFloat() + other.toFloat();
	return Fixed(ans);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	float ans = this->toFloat() - other.toFloat();
	return Fixed(ans);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	float ans = this->toFloat() * other.toFloat();
	return Fixed(ans);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	float ans = this->toFloat() / other.toFloat();
	return Fixed(ans);
}


/******** Increment/Decrement Overload *******/
Fixed& Fixed::operator++(void)
{
	this->m_n += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->m_n += 1;
	return temp;
}

Fixed& Fixed::operator--(void)
{
	this->m_n -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->m_n -= 1;
	return temp;
}

/*************** max/min *************/
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}