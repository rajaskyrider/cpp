/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:44:25 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/29 12:11:28 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__
#include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string str);
		~Zombie();

		void	announce( void );
		void	setZombie(std::string zomb);
		
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif