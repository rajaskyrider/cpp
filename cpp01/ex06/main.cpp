/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:29:24 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/30 00:55:20 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl harl;
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
	{
		std::cerr << "Enter a level" << std::endl;
		return (1);
	}
	std::string usr = argv[1];
	int choice = 5;

	for (int i = 0; i < 4; i++)
	{
		if (usr == lvl[i])
		{
			choice = i + 1;
			break ;
		}
	}
	switch (choice)
	{
		case 1:
			harl.complain("DEBUG");
			break ;
		case 2:
			harl.complain("INFO");
			break ;
		case 3:
			harl.complain("WARNING");
			break ;
		case 4:
			harl.complain("ERROR");
			break ;
		default:
			harl.complain("ALARM");
			break ;
	}
	return (0);
}