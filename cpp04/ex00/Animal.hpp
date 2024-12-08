/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:26:11 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/06 02:03:14 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		~Animal();

		virtual void makeSound() const;
		std::string	getType() const;
		
	protected:
		std::string type;
};

#endif