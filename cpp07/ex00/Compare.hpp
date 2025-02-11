/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Compare.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:30:29 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/11 16:38:36 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __COMPARE_HPP__
# define __COMPARE_HPP__

#include <iostream>

template <typename T>
void  swap(T &a, T &b)
{
	T c;

	c = a;
	a = b;
	b = c;	
}

template <typename T>
T const& min( T const &a, T const &b)
{
	return (a < b ? a : b);
}

template <typename T>
T const& max( T const &a, T const &b)
{
	return (a > b ? a : b);
}

#endif