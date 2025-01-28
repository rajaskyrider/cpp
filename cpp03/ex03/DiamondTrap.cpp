/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:00:57 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/08 14:32:33 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name")
{
	std::cout << "| DiamondTrap | Default construstor called" << std::endl;
	this->m_name = "";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	std::cout << "| DiamondTrap | Parameterized construstor called" << std::endl;
	this->m_name = name;
}

DiamondTrap::DiamondTrap(DiamondTrap &other)
{
	std::cout << "| DiamondTrap | Copy construstor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap &other)
{
	std::cout << "| DiamondTrap | copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "| DiamondTrap | " << this->m_name << " Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am | DiamondTrap | " << this->m_name << " of |ClapTrap| " << ClapTrap::getName() << " !!"
			  << std::endl;
	std::cout << "hp : " << this->getHitPoints() << std::endl;
	std::cout << "ep : " << this->getEnergyPoints() << std::endl;
	std::cout << "ap : " << this->getAttackDamage() << std::endl;
}