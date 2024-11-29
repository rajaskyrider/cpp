/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:44:25 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/29 11:34:11 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__
#include <iostream>

class Zombie
{
	public:
		Zombie(std::string str);
		~Zombie();

		void announce( void );
		
	private:
		std::string name;
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif