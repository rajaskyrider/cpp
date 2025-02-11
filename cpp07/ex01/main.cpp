/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:16:00 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/11 17:49:20 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int n[3]= {3, 2, 1};
	std::cout << "before iter:" << n[0] << " " << n[1] << " " << n[2] << " " << std::endl;
	iter<int>(n, 3, &foo<int>);
	std::cout << "after iter:" << n[0] << " " << n[1] << " " << n[2] << " " << std::endl;

	char c[3]= {'a', 'b', 'c'};
	std::cout << "before iter:" << c[0] << " " << c[1] << " " << c[2] << " " << std::endl;
	iter(c, 3, &foo);
	std::cout << "after iter:" << c[0] << " " << c[1] << " " << c[2] << " " << std::endl;
	return (0);
}