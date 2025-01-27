/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:00:03 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/23 23:16:50 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bot = NULL;
	try
	{
		bot = new Bureaucrat(2, "npc");
		std::cout << "Creation success" << std::endl;
		bot->upGrade();
		std::cout << "Upgraded Successfully" << std::endl;
		std::cout << *bot;
		bot->upGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Bureaucrat *tom = NULL;
	try
	{
		tom = new Bureaucrat(-2, "npc");
		std::cout << "Creation success" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Bureaucrat *jerry = NULL;
	try
	{
		jerry = new Bureaucrat(150, "npc");
		std::cout << "Creation success" << std::endl;
		jerry->downGrade();
		std::cout << "Upgraded Successfully" << std::endl;
		std::cout << *jerry;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat *bot1 = NULL;
	try
	{
		bot1 = new Bureaucrat(200, "npc");
		std::cout << "Creation success" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete bot;
	delete tom;
	delete jerry;
	delete bot1;
}