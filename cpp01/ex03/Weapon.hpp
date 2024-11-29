/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:38:32 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/29 19:54:29 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string name);
		Weapon ();
		std::string	getType() const;
		void				setType(std::string name);

	private:
		std::string	m_type;

};

#endif