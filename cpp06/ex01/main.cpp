/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:06:23 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/30 17:35:24 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include "Data.hpp"

int main()
{
	Data d = {"hello", 42, 42.2f, 42.42};
	Data *ptr = new Data(d);
	Data *ans;
	uintptr_t n;
	
	std::cout << "Before Serialization" << std::endl;
	std::cout << "Address of data " << ptr << std::endl;
	std::cout << "Values " << ptr->s << " " << ptr->i << " " << ptr->f << " " << ptr->d << std::endl;
	
	n = Serialization::serialize(ptr);
	std::cout << "Uintptr: " << n <<std::endl;
	
	ans = Serialization::deserialize(n);
	std::cout << "After Serialization" << std::endl;
	std::cout << "Address of data " << ans << std::endl;
	std::cout << "Values " << ans->s << " " << ans->i << " " << ans->f << " " << ans->d << std::endl;

	delete ptr;
}