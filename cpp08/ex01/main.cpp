/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:27:15 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/12 18:00:30 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>

int main() {
    std::srand(std::time(0));

    try {
        std::cout << "==== Basic Test ====" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::cout << "\n==== Large Scale Test (10,000 numbers) ====" << std::endl;
        Span largeSpan(10000);
        std::vector<int> randomNumbers;

        // Generate 10,000 random numbers
        for (int i = 0; i < 10000; i++) {
            randomNumbers.push_back(std::rand() % 100000);  // Random numbers 0-99,999
        }

        // Add all numbers in one go (using `addNumber(vector)`)
        largeSpan.addNumber(randomNumbers);

		std::cout << "Checking for duplicates..." << std::endl;
		std::set<int> uniqueNumbers(randomNumbers.begin(), randomNumbers.end());
		std::cout << "Unique numbers count: " << uniqueNumbers.size() << std::endl;

		std::cout << "Largest number = " << *std::max_element(randomNumbers.begin(), randomNumbers.end()) << std::endl;
		std::cout << "Smallest number = " << *std::min_element(randomNumbers.begin(), randomNumbers.end()) << std::endl;

        // Validate shortest and longest spans
        std::cout << "Shortest Span (10,000 numbers): " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span (10,000 numbers): " << largeSpan.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
