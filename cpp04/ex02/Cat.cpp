/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:36:42 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/10 13:20:44 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat")
{
	this->brain = new Brain();
	std::cout << "| Cat Class | default constructor called !" << std::endl;
}

Cat::Cat(const Cat &other): AAnimal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "| Cat Class | copy constructor called !" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		std::cout << "| Cat Class | copy operator called !" << std::endl;
		AAnimal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
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