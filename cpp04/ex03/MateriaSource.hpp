/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:16:40 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/10 11:35:54 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource &other);
		MateriaSource& operator=(MateriaSource &other);
		~MateriaSource();
		void learnMateria(AMateria *mat);
		AMateria* createMateria(std::string const &type);

	
	private:
		AMateria	*m_materias[4];
		int			last_learned;
};
#endif