/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:44:29 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/10 22:27:44 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "| Cure | default constructor called !!" << std::endl;
}

Cure::Cure(const Cure& other): AMateria(other)
{
	std::cout << "| Cure | copy constructor called !!" << std::endl;
}

Cure::~Cure()
{
	std::cout << "| Cure | destructor called !!" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria *clone = new Cure(*this);
	return clone;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<  "'s wounds *" << std::endl;
}

std::string const& Cure::getType() const
{
	return this->m_type;
}