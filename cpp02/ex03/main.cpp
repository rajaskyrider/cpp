/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 02:32:36 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/07 11:35:24 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int		main()
{
	Point a;
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);
	Point point(1.0f, 1.0f);

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	Point d;
	Point e(5.0f, 0.0f);
	Point f(0.0f, 5.0f);
	Point point0(6.0f, 6.0f);

	if (bsp(d, e, f, point0))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;

	
     std::cout << "=== Test Cases for BSP ===\n";

    // Test case 1: Point inside the triangle
    std::cout << "Test case 1: Expected: Inside\n";
    Point a1(0.0f, 0.0f);
    Point b1(5.0f, 0.0f);
    Point c1(0.0f, 5.0f);
    Point point1(1.0f, 1.0f);
    if (bsp(a1, b1, c1, point1))
        std::cout << "Result: Inside\n";
    else
        std::cout << "Result: Outside\n";

    // Test case 2: Point on vertex A
    std::cout << "Test case 2: Expected: Outside\n";
    Point point2(0.0f, 0.0f);
    if (bsp(a1, b1, c1, point2))
        std::cout << "Result: Inside\n";
    else
        std::cout << "Result: Outside\n";

    // Test case 3: Point on vertex B
    std::cout << "Test case 3: Expected: Outside\n";
    Point point3(5.0f, 0.0f);
    if (bsp(a1, b1, c1, point3))
        std::cout << "Result: Inside\n";
    else
        std::cout << "Result: Outside\n";

    // Test case 4: Point on vertex C
    std::cout << "Test case 4: Expected: Outside\n";
    Point point4(0.0f, 5.0f);
    if (bsp(a1, b1, c1, point4))
        std::cout << "Result: Inside\n";
    else
        std::cout << "Result: Outside\n";

    // Test case 5: Point on edge AB
    std::cout << "Test case 5: Expected: Outside\n";
    Point point5(2.5f, 0.0f);
    if (bsp(a1, b1, c1, point5))
        std::cout << "Result: Inside\n";
    else
        std::cout << "Result: Outside\n";

    // Test case 6: Point on edge AC
    std::cout << "Test case 6: Expected: Outside\n";
    Point point6(0.0f, 2.5f);
    if (bsp(a1, b1, c1, point6))
        std::cout << "Result: Inside\n";
    else
        std::cout << "Result: Outside\n";

    // Test case 7: Point on edge BC
    std::cout << "Test case 7: Expected: Outside\n";
    Point point7(2.5f, 2.5f);
    if (bsp(a1, b1, c1, point7))
        std::cout << "Result: Inside\n";
    else
        std::cout << "Result: Outside\n";

    // Test case 8: Point outside the triangle
    std::cout << "Test case 8: Expected: Outside\n";
    Point point8(6.0f, 6.0f);
    if (bsp(a1, b1, c1, point8))
        std::cout << "Result: Inside\n";
    else
        std::cout << "Result: Outside\n";
}