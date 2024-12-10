/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:53:51 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/08 23:29:42 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		~Dog();

		virtual void 		makeSound() const;
		std::string	getType() const;
};

#endif