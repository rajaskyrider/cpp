/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:28 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/12 16:05:28 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>	

int main()
{
	std::list<int>				ptr;
	std::list<int>::iterator	it;

	ptr.push_back(1);
	ptr.push_back(2);
	ptr.push_back(3);

	try
	{
		it = easyfind<std::list<int> >(ptr, 2);
		std::cout << "Found element " << *it << std::endl;
	}
	catch(const ElementNotFoundException& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		it = easyfind<std::list<int> >(ptr, 20);
		std::cout << "Found element " << *it << std::endl;
	}
	catch(const ElementNotFoundException& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    try {
        std::vector<int>::iterator it = easyfind(numbers, 30);
        std::cout << "Found element: " << *it << std::endl;
    } catch (const ElementNotFoundException& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        std::vector<int>::iterator it = easyfind(numbers, 100);
        std::cout << "Found element: " << *it << std::endl;
    } catch (const ElementNotFoundException& e) {
        std::cerr << e.what() << '\n';
    }

}