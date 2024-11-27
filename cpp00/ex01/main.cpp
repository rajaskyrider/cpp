/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:51:46 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/27 18:14:59 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string choice;
	std::string	contact;
	int	index = 0;
	int search = 0;
	PhoneBook	phone;

	std::cout << "Welcome to the crappy awesome phonebook" << std::endl;
	while (1)
	{
		std::cout << "Please enter a command" <<std::endl;
		std::cout << "\t Enter ADD to add a contact"<<std::endl;
		std::cout << "\t Enter SEARCH to search a contact"<<std::endl;
		std::cout << "\t Enter EXIT to exit phonebook"<<std::endl;
		std::cin >> choice;
		if (choice == "ADD")
		{
			phone.addContact(index);
			index++;
		}
		else if (choice == "SEARCH")
		{
			phone.searchContact();
			std::cout << "Please enter an index to display more info : ";
			if (std::cin >> search)
				phone.printContact(search);
			else
				std::cout << "Invalid index" << std::endl;
		}
		else if (choice == "EXIT")
			break ;
		else
			std::cout << "Please enter a valid command" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "Bye !!" << std::endl;
	return 0;
}