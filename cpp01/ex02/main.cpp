/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:06:46 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/29 16:03:46 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str; 

	std::cout << "str variable memory: " << &str << std::endl;
	std::cout << "stringPTR memory: " << stringPTR << std::endl;
	std::cout << "stringREF memory: " << &stringREF << std::endl;
	std::cout << "str variable value: " << str << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;
}