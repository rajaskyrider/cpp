/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:34:12 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/04 16:57:07 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name(""), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "| ClapTrap | Default construstor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "| ClapTrap | Copy construstor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "| ClapTrap | Parameterized construstor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->m_name = other.m_name;
		this->m_hitPoints = other.m_hitPoints;
		this->m_energyPoints = other.m_energyPoints;
		this->m_attackDamage = other.m_attackDamage;
	}
	std::cout << "| ClapTrap | copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "| ClapTrap | " << (m_name.empty() ? "(Unnamed)" : m_name) << " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->m_hitPoints > 0 && this->m_energyPoints > 0)
	{
		std::cout << "| ClapTrap | " << this->m_name << " attacks " << target << ", causing " << this->m_attackDamage << " points of damage!"
				  << std::endl;
		this->m_energyPoints -= 1;
	}
	else
		std::cout << "| ClapTrap | " << this->m_name << " cannot attack" << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->m_hitPoints > 0 && this->m_energyPoints > 0)
	{
		std::cout << "| ClapTrap | " << this->m_name << " recovered " << amount << " of hit points!"
				  << std::endl;
		this->m_energyPoints -= 1;
		this->m_hitPoints += amount;
	}
	else
		std::cout << "| ClapTrap | " << this->m_name << " cannot be repaired" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hitPoints > 0)
	{
		unsigned int hitPoints = static_cast<unsigned int>(m_hitPoints);
		std::cout << "| ClapTrap|  " << this->m_name << " was attacked and lost " << amount << " of hit points!"
				<< std::endl;
		this->m_hitPoints = (amount > hitPoints) ? 0 : this->m_hitPoints - amount;;
	}
	else
		std::cout<< "| ClapTrap | " << this->m_name << " is already dead" << std::endl;
}

std::string	ClapTrap::getName() const
{
	return this->m_name;
}

void		ClapTrap::setName(const std::string name)
{
	this->m_name = name;
}

int			ClapTrap::getHitPoints() const
{
	return this->m_hitPoints;
}

void		ClapTrap::setHitPoints(const int hp)
{
	this->m_hitPoints = hp;
}

int			ClapTrap::getEnergyPoints() const
{
	return this->m_energyPoints;
}

void		ClapTrap::setEnergyPoints(const int ep)
{
	this->m_energyPoints = ep;
}

int			ClapTrap::getAttackDamage() const
{
	return this->m_attackDamage;
}

void		ClapTrap::setAttackDamage(const int ad)
{
	this->m_attackDamage = ad;
}