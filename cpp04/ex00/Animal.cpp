/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:25:53 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/06 02:01:14 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "| Animal Class | default constructor called !" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
	std::cout << "| Animal Class | parameterized constructor called !" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "| Animal Class | copy constructor called !" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "| Animal Class | copy operator called !" << std::endl;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "| Animal Class | destructor called !" << std::endl;
}

std::string	Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Animal Grunts!!" << std::endl;
}