/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:22:55 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/06 13:48:04 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int N = 5;
	Zombie* heapZombie = zombieHorde(N, "heap");
	
	if (heapZombie == NULL)
		return (1);
	for (int i=0; i < N; i++)
		heapZombie[i].announce();
	delete[] heapZombie;
	return (0);
}