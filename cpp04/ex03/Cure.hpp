/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:43:58 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/09 23:44:25 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Cure_HPP__
# define __Cure_HPP__

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		~Cure();
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
	private:
		Cure& operator=(const Cure& other);
};

#endif