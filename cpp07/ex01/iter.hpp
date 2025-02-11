/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:11:12 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/11 17:49:32 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
# define __ITER_HPP__

#include <iostream>

template <typename T>
void iter(T *ptr, int n, void (*func)(T const&))
{
	for (int i = 0; i < n; i++)
		func(ptr[i]);	
}

template <typename T>
void foo(T const &num)
{
	std::cout << "element is " << num << std::endl;
}

#endif