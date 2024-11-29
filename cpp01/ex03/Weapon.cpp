/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:43:26 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/29 20:01:44 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name) : m_type(name){}

Weapon::Weapon() : m_type(""){}

std::string	Weapon::getType() const
{
	return this->m_type;
}

void	Weapon::setType(std::string name)
{
	this->m_type = name;
}