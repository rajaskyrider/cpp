/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:36:42 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/06 01:59:10 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "| WrongCat Class | default constructor called !" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
	std::cout << "| WrongCat Class | copy constructor called !" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		std::cout << "| WrongCat Class | copy operator called !" << std::endl;
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "| WrongCat Class | destructor called !" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat meows!!" << std::endl;
}

std::string	WrongCat::getType() const
{
	return this->type;
}