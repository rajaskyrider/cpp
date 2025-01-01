/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:37:23 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/01 16:57:21 by rpandipe         ###   ########.fr       */
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

void	PhoneBook::truncateContact(std::string txt) const
{
	std::cout << std::setw(10) << std::right;
	if (txt.size() > 10)
		std::cout << txt.substr(0, 9) + "." << "|";
	else
		std::cout << txt << "|";
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
