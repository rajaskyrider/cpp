/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:02:57 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/09 23:43:35 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "| Ice | default constructor called !!" << std::endl;
}

Ice::Ice(const Ice& other): AMateria(*this)
{
	std::cout << "| Ice | copy constructor called !!" << std::endl;
}

Ice::~Ice()
{
	std::cout << "| Ice | destructor called !!" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria *clone = new Ice(*this);
	return clone;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
}