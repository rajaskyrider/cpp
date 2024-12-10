/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:26:11 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/09 01:15:58 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string name);
		AAnimal(const AAnimal &other);
		AAnimal& operator=(const AAnimal &other);
		virtual ~AAnimal();

		virtual void makeSound() const = 0;
		std::string	getType() const;
		
	protected:
		std::string type;
};

#endif