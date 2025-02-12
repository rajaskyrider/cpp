/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:37:40 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/12 15:56:45 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &cnt, int n);

class ElementNotFoundException: public std::exception
{
	public:
		const char* what() const throw();	
};

#include "easyfind.tpp"

#endif