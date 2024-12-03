/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 02:32:36 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/03 02:36:59 by rpandipe         ###   ########.fr       */
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
	Point point1(6.0f, 6.0f);

	if (bsp(d, e, f, point1))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
}