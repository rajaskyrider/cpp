/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:42:04 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/09 22:24:57 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string const m_type;

	public:
		AMateria(std::string const & type);
		AMateria(AMateria& other);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria();

	private:
		AMateria();
		AMateria& operator=(const AMateria &other);

};

#endif