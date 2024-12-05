/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:15:56 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/04 16:52:05 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap(const std::string &name);
		ClapTrap& operator=(const ClapTrap &other);
		~ClapTrap();

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	protected:
		std::string	getName() const;
		void		setName(const std::string name);
		int			getHitPoints() const;
		void		setHitPoints(const int hp);
		int			getEnergyPoints() const;
		void		setEnergyPoints(const int ep);
		int			getAttackDamage() const;
		void		setAttackDamage(const int ad);

	private:
		std::string	m_name;
		int			m_hitPoints;
		int			m_energyPoints;
		int			m_attackDamage;

};

#endif