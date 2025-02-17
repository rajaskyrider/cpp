/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:21:18 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/17 10:41:44 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

int main()
{
	clock_t start, end;
	PmergeMe psort;
	std::vector<int> n;

	n.push_back(2);
	n.push_back(5);
	n.push_back(7);
	n.push_back(9);
	n.push_back(10);
	n.push_back(1);
	n.push_back(3);
	n.push_back(4);
	n.push_back(6);
	n.push_back(8);
	n.push_back(11);
	std::cout << "Unorted Array: ";
	for (size_t i = 0; i < n.size(); i++)
			std::cout << n[i] << " ";
	std::cout << std::endl;
	start = clock();
	psort.sortVector(n);
	end = clock();
	std::cout << "Sorted Array: ";
	for (size_t i = 0; i < n.size(); i++)
			std::cout << n[i] << " ";
	std::cout << std::endl;
	double elapsed_time_micro = static_cast<double>(end - start) * (1000000.0 / CLOCKS_PER_SEC);
	std::cout << "Execution time: " << elapsed_time_micro << " µs" << std::endl;
}