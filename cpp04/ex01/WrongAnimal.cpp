/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:43:43 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/08 12:45:02 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "| WrongAnimal Class | default constructor called !" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type(name)
{
	std::cout << "| WrongAnimal Class | parameterized constructor called !" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "| WrongAnimal Class | copy constructor called !" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "| WrongAnimal Class | copy operator called !" << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "| WrongAnimal Class | destructor called !" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Grunts!!" << std::endl;
}