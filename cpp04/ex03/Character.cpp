/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:00:49 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/10 22:28:19 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name): m_name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = NULL;
		this->floor[i] = NULL;
	}
	std::cout << "| Character | " << name << " parameterized constructor called !!" << std::endl; 
}

Character::Character(const Character& other): m_name(other.m_name)
{
	std::cout << "| Character | copy constructor called !!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.slot[i] != NULL)
			this->slot[i] = other.slot[i]->clone();
		else
			this->slot[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (other.floor[i] != NULL)
			this->floor[i] = other.floor[i]->clone();
		else
			this->floor[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	std::cout << "| Character | copy operator called !!" << std::endl; 
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->slot[i] != NULL)
				delete this->slot[i];
			this->slot[i] = (other.slot[i] != NULL) ? other.slot[i]->clone() : NULL;
			if (this->floor[i] != NULL)
				delete this->floor[i];
			this->floor[i] = (other.floor[i] != NULL) ? other.floor[i]->clone() : NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "| Character | destructor called !!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->slot[i];
		delete this->floor[i];
	}
}

std::string const& Character::getName() const
{
	return this->m_name;
}

void Character::equip(AMateria* m)
{
	int	idx = 0;
	
	while(this->slot[idx] != NULL && idx < 4)
		idx++;
	if (idx < 4)
		slot[idx] = m;
}

void Character::unequip(int idx)
{
	if (slot[idx] != NULL)
	{
		delete floor[idx];
		floor[idx] = slot[idx];
		slot[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (slot[idx] != NULL)
		slot[idx]->use(target);
}