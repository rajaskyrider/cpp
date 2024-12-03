/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:34:12 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/03 21:22:41 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name(""), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap Default construstor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap Copy construstor called" << std::endl;

}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap Parameterized construstor called" << std::endl;
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
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << m_name << " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->m_hitPoints > 0 && this->m_energyPoints > 0)
	{
		std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!"
				  << std::endl;
		m_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << m_name << "cannot attack" << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->m_hitPoints > 0 && this->m_energyPoints > 0)
	{
		std::cout << "ClapTrap " << m_name << " recovered " << amount << " of hit points!"
				  << std::endl;
		m_energyPoints -= 1;
		m_hitPoints += amount;
	}
	else
		std::cout << "ClapTrap " << m_name << "cannot be repaired" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hitPoints > 0)
	{
		std::cout << "ClapTrap " << m_name << " was attacked and lost " << amount << " of hit points!"
				<< std::endl;
		m_hitPoints -= amount;
	}
	else
		std::cout<< "ClapTrap " << m_name << "is already dead" << std::endl;
}