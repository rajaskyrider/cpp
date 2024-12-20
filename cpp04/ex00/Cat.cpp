/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:36:42 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/08 12:36:57 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "| Cat Class | default constructor called !" << std::endl;
}

Cat::Cat(Cat &other): Animal(other)
{
	std::cout << "| Cat Class | copy constructor called !" << std::endl;
}

Cat& Cat::operator=(Cat &other)
{
	if (this != &other)
	{
		std::cout << "| Cat Class | copy operator called !" << std::endl;
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "| Cat Class | destructor called !" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat meows!!" << std::endl;
}

std::string	Cat::getType() const
{
	return this->type;
}