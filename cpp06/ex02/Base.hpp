/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:43:12 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/30 18:07:06 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP__
# define __BASE_HPP__

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
	public:
		virtual ~Base();	
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif