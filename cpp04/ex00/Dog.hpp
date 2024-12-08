/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:53:51 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/06 02:03:17 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(Dog &other);
		Dog& operator=(Dog &other);
		~Dog();

		virtual void 		makeSound() const;
		std::string	getType() const;
};

#endif