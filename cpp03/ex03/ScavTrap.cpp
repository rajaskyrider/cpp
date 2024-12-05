/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:49:52 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/05 14:29:31 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "| ScavTrap | Default construstor called" << std::endl;
	this->setEnergyPoints(50);
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
	std::cout << "| ScavTrap | Copy construstor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "| ScavTrap | Parameterized construstor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "| ScavTrap | copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "| ScavTrap | " << (this->getName().empty() ? "(Unnamed)" : this->getName()) << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
	{
		std::cout << "| ScavTrap | " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!"
				  << std::endl;
		int ep = this->getEnergyPoints();
		this->setEnergyPoints(ep - 1);
	}
	else
		std::cout << "| ScavTrap | " << this->getName() << " cannot attack" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->getEnergyPoints() > 0)
	{
		std::cout << "| ScavTrap | " << this->getName() << "is now in Gate keeper mode" << std::endl;
		int ep = this->getEnergyPoints();
		this->setEnergyPoints(ep - 1);
	}
	else
		std::cout << "| ScavTrap | " << this->getName() << " has no energy left!!" << std::endl;
}
