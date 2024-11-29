/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:41:27 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/30 00:56:02 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			  << std::endl;
	std::cout << std::endl;
}

void Harl::info(void) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
			  << std::endl;
	std::cout << std::endl;
}

void Harl::error(void) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level) const
{
	void (Harl::*func_ptr[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	bool flag = false;

	for (int i = 0; i < 4; i++)
	{
		if (level == lvl[i])
			flag = true;
		if (flag)
			(this->*func_ptr[i])();
	}
	if (!flag)
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
}