/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:43:38 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/30 17:33:02 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZATION_HPP__
# define __SERIALIZATION_HPP__

#include <iostream>
#include "Data.hpp"


typedef unsigned long int uintptr_t;
class Serialization
{
	private:
		Serialization();
		Serialization(const Serialization &other);
		Serialization& operator=(const Serialization &other);
		~Serialization();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);	
};

#endif