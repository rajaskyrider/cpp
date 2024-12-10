/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:25:53 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/09 01:16:43 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal")
{
	std::cout << "| AAnimal Class | default constructor called !" << std::endl;
}

AAnimal::AAnimal(std::string name) : type(name)
{
	std::cout << "| AAnimal Class | parameterized constructor called !" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other): type(other.type)
{
	std::cout << "| AAnimal Class | copy constructor called !" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "| AAnimal Class | copy operator called !" << std::endl;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "| AAnimal Class | destructor called !" << std::endl;
}

std::string	AAnimal::getType() const
{
	return this->type;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal Grunts!!" << std::endl;
}