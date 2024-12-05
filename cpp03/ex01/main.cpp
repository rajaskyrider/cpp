/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:35:36 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/04 11:43:58 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap trap("Serena");
	ScavTrap trap2;
	
	trap.attack("npc");
	trap.takeDamage(50);
	trap.beRepaired(40);
	trap.guardGate();

	trap2.attack("npc2");
	trap2.takeDamage(50);
	trap2.beRepaired(40);
	trap2.guardGate();

	return 0;
}