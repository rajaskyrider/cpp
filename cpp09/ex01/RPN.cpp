/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:52:05 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/15 23:19:17 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &other): m_ans(other.m_ans){}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
		m_ans = other.m_ans;
	return (*this);
}

RPN::~RPN(){};

void RPN::calculate(const std::string& exp)
{
	int n;
	std::string token;
	std::stringstream ss(exp);

	while (ss >> token)
	{
		std::stringstream convert(token);
		if (convert >> n)
		{
			if (n < 0  || n > 10)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			m_ans.push(n);
		}
		else if (!operate(token[0]))
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}
	if (m_ans.size() == 1)
		std::cout << m_ans.top() << std::endl;
	else
		std::cerr << "Error" << std::endl;
}

bool RPN::operate(char op)
{
	int lhs, rhs;

	if (!(op == '+' || op == '-' || op == '*' || op == '/') && (m_ans.size() < 2))
		return (false);
	rhs = m_ans.top();
	m_ans.pop();
	lhs = m_ans.top();
	m_ans.pop();
	if (op == '+')
		m_ans.push(lhs + rhs);
	else if (op == '-')
		m_ans.push(lhs - rhs);
	else if (op == '*')
		m_ans.push(lhs * rhs);
	else if (op == '/' && rhs != 0)
		m_ans.push(lhs / rhs);
	else
		return (false);
	return (true);	
}	