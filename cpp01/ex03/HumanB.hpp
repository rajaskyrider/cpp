/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:58:12 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/29 20:08:33 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void	attack() const;
		void	setWeapon(Weapon &weapon);

	private:
		std::string m_name;
		Weapon		*m_weapon;
};

#endif