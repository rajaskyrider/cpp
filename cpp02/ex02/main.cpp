/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:23:11 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/03 00:56:22 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2)); // b = 10.1

    std::cout << "Initial Tests:" << std::endl;
    std::cout << "a: " << a << " (expected: 0)" << std::endl;
    std::cout << "++a: " << ++a << " (expected: 0.00390625)" << std::endl;
    std::cout << "a: " << a << " (expected: 0.00390625)" << std::endl;
    std::cout << "a++: " << a++ << " (expected: 0.00390625)" << std::endl;
    std::cout << "a: " << a << " (expected: 0.0078125)" << std::endl;
    std::cout << "b: " << b << " (expected: 10.1)" << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << " (expected: 10.1)" << std::endl;

    if (b > a)
        std::cout << "True (expected: True)" << std::endl;
    else
        std::cout << "False (expected: False)" << std::endl;

    std::cout << std::endl;

    // Arithmetic operator tests
    Fixed c(5);
    Fixed d(4);
    std::cout << "Arithmetic Tests:" << std::endl;
    std::cout << "5 + 4 = " << (c + d) << " (expected: 9)" << std::endl;
    std::cout << "5 - 4 = " << (c - d) << " (expected: 1)" << std::endl;
    std::cout << "5 * 4 = " << (c * d) << " (expected: 20)" << std::endl;
    std::cout << "5 / 4 = " << (c / d) << " (expected: 1.25)" << std::endl;

    std::cout << std::endl;

    // Comparison operator tests
    std::cout << "Comparison Tests:" << std::endl;
    std::cout << "5 > 4: " << (c > d ? "True" : "False") << " (expected: True)" << std::endl;
    std::cout << "5 < 4: " << (c < d ? "True" : "False") << " (expected: False)" << std::endl;
    std::cout << "5 >= 4: " << (c >= d ? "True" : "False") << " (expected: True)" << std::endl;
    std::cout << "5 <= 4: " << (c <= d ? "True" : "False") << " (expected: False)" << std::endl;
    std::cout << "5 == 4: " << (c == d ? "True" : "False") << " (expected: False)" << std::endl;
    std::cout << "5 != 4: " << (c != d ? "True" : "False") << " (expected: True)" << std::endl;

    std::cout << std::endl;

    // Increment/Decrement operator tests
    Fixed e(10);
    std::cout << "Increment/Decrement Tests:" << std::endl;
    std::cout << "e: " << e << " (expected: 10)" << std::endl;
    std::cout << "++e: " << ++e << " (expected: 10.00390625)" << std::endl;
    std::cout << "e++: " << e++ << " (expected: 10.00390625)" << std::endl;
    std::cout << "e: " << e << " (expected: 10.0078125)" << std::endl;
    std::cout << "--e: " << --e << " (expected: 10.00390625)" << std::endl;
    std::cout << "e--: " << e-- << " (expected: 10.00390625)" << std::endl;
    std::cout << "e: " << e << " (expected: 10)" << std::endl;

    std::cout << std::endl;

    // Max/Min tests
    Fixed f(15);
    Fixed g(20);
    std::cout << "Max/Min Tests:" << std::endl;
    std::cout << "max(15, 20): " << Fixed::max(f, g) << " (expected: 20)" << std::endl;
    std::cout << "min(15, 20): " << Fixed::min(f, g) << " (expected: 15)" << std::endl;

    const Fixed cf(30);
    const Fixed cg(25);
    std::cout << "max(30, 25): " << Fixed::max(cf, cg) << " (expected: 30)" << std::endl;
    std::cout << "min(30, 25): " << Fixed::min(cf, cg) << " (expected: 25)" << std::endl;

    std::cout << std::endl;

    return 0;
}