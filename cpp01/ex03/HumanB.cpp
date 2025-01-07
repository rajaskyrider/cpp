/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:58:14 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/06 15:02:17 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL) {}

void	HumanB::attack() const
{
	if (m_weapon == NULL)
		std::cout << this->m_name <<  " attacks with their fists" << std::endl;
	else
		std::cout << this->m_name <<  " attacks with their " << this->m_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->m_weapon = &weapon;
}