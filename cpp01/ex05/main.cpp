/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:29:24 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/30 00:40:46 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << std::endl << "------ DEBUG Level ------" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "------ INFO Level ------" << std::endl;;
	harl.complain("INFO");
	std::cout << std::endl << "------ WARNING Level ------" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "------ ERROR Level ------" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl << "------ No valid Level ------" << std::endl;
	harl.complain("ALARM");
	return (0);
}