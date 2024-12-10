/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:27:59 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/10 11:43:33 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): last_learned(0)
{
	for (int i = 0; i < 4; i++)
		this->m_materias[i] = NULL;
	std::cout << "| MateriaSource | default constructor called !!" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource &other): last_learned(other.last_learned)
{
	std::cout << "| MateriaSource | copy constructor called !!" << std::endl;
	for (int i = 0; i < 4; i++)
		this->m_materias[i] = other.m_materias[i]->clone();
}

MateriaSource& MateriaSource::operator=(MateriaSource &other)
{
	std::cout << "| MateriaSource | copy operator called !!" << std::endl;
	if (this != &other)
	{
		this->last_learned = other.last_learned;
		for (int i = 0; i < 4; i++)
		{
			delete this->m_materias[i];
			this->m_materias[i] = other.m_materias[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "| MateriaSource | destructor called !!" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->m_materias[i];
}

void MateriaSource::learnMateria(AMateria *mat)
{
	delete m_materias[last_learned];
	this->m_materias[this->last_learned] = mat->clone();
	last_learned = (last_learned == 3) ? 0 : last_learned + 1;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->m_materias[i] != NULL && this->m_materias[i]->getType() == type)
			return this->m_materias[i]->clone();
	}
	return 0;
}