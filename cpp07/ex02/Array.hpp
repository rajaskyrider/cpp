/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:27:46 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/12 13:55:20 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <iostream>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array<T> const &other);
		Array<T>& operator=(Array<T> const &other);
		~Array();
		const T& operator[](unsigned int i) const;
		T& operator[](unsigned int i);
		
		unsigned int size() const;
		T* getArray() const;

		class IndexOutOfBoundsException : public std::exception
		{
			public:
				const char* what() const throw();
		};
	
	private:
		unsigned int m_n;
		T *m_ptr;	
			
};

#include "Array.tpp"

#endif