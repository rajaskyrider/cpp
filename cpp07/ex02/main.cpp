/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:27:50 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/12 13:54:52 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> a(10);

    a[0] = 42;
    a[9] = 99;

    std::cout << "a[0] = " << a[0] << ", a[9] = " << a[9] << std::endl;

    try
	{
        std::cout << a[10] << " this" << std::endl;
    }
	catch (const std::exception &e) 
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}