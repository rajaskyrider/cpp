/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:46:45 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/11 11:43:43 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void)
{
	int	n;
	
	n = std::rand() % 3;
	switch(n)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Actual type is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Actual type is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Actual type is C" << std::endl;
	else
		std::cout << "Type cannot be identitifed" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A &>(p);
		std::cout << "Actual type of reference is A" << std::endl;
		return ;
	}
	catch(...){}
	try
	{
		(void) dynamic_cast<B &>(p);
		std::cout << "Actual type of reference is B" << std::endl;
		return ;
	}
	catch(...){}
	try
	{
		(void) dynamic_cast<C &>(p);
		std::cout << "Actual type of reference is C" << std::endl;
		return ;
	}
	catch(...){}
	std::cout << "Type cannot be identitifed" << std::endl;
}