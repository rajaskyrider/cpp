/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:08:21 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/06 13:45:21 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
	{
		std::cout << "A Horde can not contain less than 1 Zombie." << std::endl;
		return (NULL);
	}
	Zombie *hoarde = new Zombie[N];
	if (hoarde == NULL)
	{
		std::cout << "Allocation of the horde failed." << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		hoarde[i].setZombie(name);
	return hoarde;
}