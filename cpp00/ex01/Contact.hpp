/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:10:47 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/01 16:55:54 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>


class Contact{
	public:
		void	setFields();
		void	printFields() const;
		void	truncateFields() const;
		int 	checkEmpty() const;

	private:
		std::string	m_firstname;
		std::string	m_lastname;
		std::string	m_nickname;
		std::string	m_number;
		std::string	m_secret;
		std::string	checkContact(std::string str);
		void	truncateContact(std::string txt) const;
};

#endif