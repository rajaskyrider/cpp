/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:00:37 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/10 10:30:07 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character: public ICharacter
{
	public:
		Character(std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		Character();

		std::string m_name;
		AMateria *slot[4];
		AMateria *floor[4];
};

#endif