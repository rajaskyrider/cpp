/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:10:29 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/27 18:03:49 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook{
	public:
		void		addContact(int index);
		std::string	checkContact(std::string str);
		void		searchContact(void) const;
		void		printContact(int index) const;
		void		truncateContact(std::string txt) const;
	
	private:
		Contact contacts[8];
};

#endif