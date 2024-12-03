/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:17:11 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/03 21:23:04 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap bot("bot");
	ClapTrap npc(bot);
	ClapTrap dummy;

	bot.attack("enemy");
	bot.takeDamage(8);
	bot.beRepaired(6);
	dummy = npc;
	dummy.attack("enemy2");
	dummy.takeDamage(10);
	dummy.beRepaired(5);
	dummy.attack("enemy2");
	return 0;
}