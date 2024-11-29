/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:37:34 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/29 22:40:55 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <iostream>

class Harl
{
	public:
		void complain(std::string level) const;
	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;
};

#endif