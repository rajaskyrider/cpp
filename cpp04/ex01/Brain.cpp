/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:43:34 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/09 00:04:43 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "| Brain Class | default constructor called !" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "| Brain Class | copy constructor called !" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
	if(this != &other)
	{
		for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = other.ideas[i];
        }
		std::cout << "| Brain Class | copy operator called !" << std::endl;
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "| Brain Class | destructor called !" << std::endl;
}