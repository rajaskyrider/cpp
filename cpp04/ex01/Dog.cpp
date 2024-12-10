/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:53:47 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/08 23:42:02 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), brain(new Brain())
{
	std::cout << "| Dog Class | default constructor called !" << std::endl;
}

Dog::Dog(const Dog &other): Animal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "| Dog Class | copy constructor called !" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		std::cout << "| Dog Class | copy operator called !" << std::endl;
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "| Dog Class | destructor called !" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog barks!!" << std::endl;
}

std::string	Dog::getType() const
{
	return this->type;
}