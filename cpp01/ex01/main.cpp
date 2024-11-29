/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:22:55 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/29 12:13:14 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int N = 5;
	Zombie* heapZombie = zombieHorde(N, "heap");

	for (int i=0; i < N; i++)
		heapZombie[i].announce();
	delete[] heapZombie;
}