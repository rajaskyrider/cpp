/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:38:43 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/04 16:28:43 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap(const std::string &name);
		FragTrap&	operator=(const FragTrap &other);
		~FragTrap();
		
		void highFivesGuys(void);

};

#endif

