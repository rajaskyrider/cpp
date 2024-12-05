/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:38:43 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/04 23:49:24 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap(const std::string &name);
		ScavTrap&	operator=(const ScavTrap &other);
		~ScavTrap();
		
		void	guardGate();
		void	attack(const std::string& target);
	private:

};

#endif

