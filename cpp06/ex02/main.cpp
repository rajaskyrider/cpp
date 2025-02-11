/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:26:02 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/11 11:40:39 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	std::srand(time(0));
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}