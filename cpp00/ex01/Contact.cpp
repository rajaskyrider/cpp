/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:04:06 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/01 16:57:05 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::checkContact(std::string str)
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

void Contact::setFields()
{
	this->m_firstname= checkContact("first name : ");
	this->m_lastname = checkContact("last name : ");
	this->m_nickname = checkContact("nick name : ");
	this->m_number = checkContact("Phone number : ");
	this->m_secret = checkContact("Darkest secret : ");
}

void Contact::printFields() const
{
	std::cout << "First name : " << this->m_firstname << std::endl;
	std::cout << "Last name : " << this->m_lastname << std::endl;
	std::cout << "Nick name : " << this->m_nickname << std::endl;
	std::cout << "Phone Number : " << this->m_number << std::endl;
	std::cout << "Darkest Secret : " << this->m_secret << std::endl;
}

void	Contact::truncateContact(std::string txt) const
{
	std::cout << std::setw(10) << std::right;
	if (txt.size() > 10)
		std::cout << txt.substr(0, 9) + "." << "|";
	else
		std::cout << txt << "|";
}

void Contact::truncateFields() const
{
	truncateContact(this->m_firstname);
	truncateContact(this->m_lastname);
	truncateContact(this->m_nickname);
	std::cout << std::endl;
}

int Contact::checkEmpty() const
{
	if (this->m_firstname.empty())
		return 1;
	return 0;
}