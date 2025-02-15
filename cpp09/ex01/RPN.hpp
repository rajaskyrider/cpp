/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:40:54 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/15 23:03:05 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__

#include <iostream>
#include <sstream>
#include <stack>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();

		void calculate(const std::string& exp);
		bool operate (char op);

	private:
		std::stack<double> m_ans; 
};

#endif