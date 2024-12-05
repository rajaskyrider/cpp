/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:49:52 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/04 16:56:14 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "| FragTrap | Default construstor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
	std::cout << "| FragTrap | Copy construstor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "| FragTrap | Parameterized construstor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap&	FragTrap::operator=(const FragTrap &other)
{
	std::cout << "| FragTrap | copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "| FragTrap | " << (this->getName().empty() ? "(Unnamed)" : this->getName()) << " destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (this->getEnergyPoints() > 0)
	{
		std::cout << "| FragTrap | " << this->getName() << "high fives you !!" << std::endl;
		int ep = this->getEnergyPoints();
		this->setEnergyPoints(ep - 1);
	}
	else
		std::cout << "| FragTrap | " << this->getName() << " has no energy left!!" << std::endl;
}