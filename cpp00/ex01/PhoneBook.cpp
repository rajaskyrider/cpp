/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:37:23 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/27 18:08:37 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string PhoneBook::checkContact(std::string str)
{
	std::string val;
	
	while (1)
	{
		std::cout << str;
		std::getline(std::cin, val);
		if (!val.empty())
			break ;
	}
	return val;
}

void	PhoneBook::addContact(int index)
{
	index = index % 8;
	
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	this->contacts[index].firstname = checkContact("first name : ");
	this->contacts[index].lastname = checkContact("last name : ");
	this->contacts[index].nickname = checkContact("nick name : ");
	this->contacts[index].number = checkContact("Phone number : ");
	this->contacts[index].secret = checkContact("Darkest secret : ");
}

void	PhoneBook::printContact(int index) const
{
	index--;
	if (index >= 0 && index < 8 && !this->contacts[index].firstname.empty())
	{
		std::cout << "First name : " << this->contacts[index].firstname << std::endl;
		std::cout << "Last name : " << this->contacts[index].lastname << std::endl;
		std::cout << "Nick name : " << this->contacts[index].nickname << std::endl;
		std::cout << "Phone Number : " << this->contacts[index].number << std::endl;
		std::cout << "Darkest Secret : " << this->contacts[index].secret << std::endl;
	}
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
		if (!this->contacts[i].firstname.empty())
		{
			std::cout << "|" << std::setfill(' ') 
			  << std::setw(10) << std::right << i + 1 << "|";
			truncateContact(this->contacts[i].firstname);
			truncateContact(this->contacts[i].lastname);
			truncateContact(this->contacts[i].nickname);
			std::cout << std::endl;
		}
		else
			break ;
	}
	std::cout << std::endl << std::endl;
}
