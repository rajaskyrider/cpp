/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:42:00 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/10 22:03:19 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*AMateria::AMateria(): m_type("")
{
	std::cout << "| AMateria | default constructor called !!" << std::endl;
}*/

AMateria::AMateria(std::string const & type): m_type(type)
{
	std::cout << "| AMateria | paramaterized constructor called !!" << std::endl;
}

AMateria::AMateria(const AMateria& other): m_type(other.m_type)
{
	std::cout << "| AMateria | copy constructor called !!" << std::endl;
}

/*AMateria& AMateria::operator=(const AMateria &other)
{
	std::cout << "| AMateria | copy operator called !!" << std::endl;
	return *this;
}*/

AMateria::~AMateria()
{
	std::cout << "| AMateria | destructor called !!" << std::endl;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria " << this->m_type << " used on " << target.getName() << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->m_type;
}
