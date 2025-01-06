/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:37:23 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/06 10:26:02 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addContact(int index)
{
	index = index % 8;
	
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->contacts[index].setFields();
}

void	PhoneBook::printContact(int index) const
{
	index--;
	if (index >= 0 && index < 8 && !this->contacts[index].checkEmpty())
		this->contacts[index].printFields();
	else
		std::cout << "Index out of range !!" << std::endl;
	std::cout << std::endl << std::endl;
}

void	PhoneBook::searchContact(void) const
{
	std::cout << "|" << std::setfill(' ') 
			  << std::setw(10) << std::right << "index" << "|"
              << std::setw(10) << std::right << "first name" << "|"
              << std::setw(10) << std::right << "last name" << "|"
              << std::setw(10) << std::right << "nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!this->contacts[i].checkEmpty())
		{
			std::cout << "|" << std::setfill(' ') 
			  << std::setw(10) << std::right << i + 1 << "|";
			this->contacts[i].truncateFields();
			std::cout << std::endl;
		}
		else
			break ;
	}
	std::cout << std::endl << std::endl;
}
