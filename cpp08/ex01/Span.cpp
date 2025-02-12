/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:55:55 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/12 17:46:50 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(int N)
{
	m_N = static_cast<unsigned int>(N);
	m_v = new std::vector<int>;
}

Span::Span(const Span &other): m_N(other.m_N), m_v(new std::vector<int>(*other.m_v))
{}

Span& Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	this->m_N = other.m_N;
	delete m_v;
	m_v = new std::vector<int>;
	if (!other.m_v->empty())
		m_v->insert(m_v->begin(), other.m_v->begin(), other.m_v->end());
	return (*this);
}

Span::~Span()
{
	delete m_v;
}

void Span::addNumber(int num)
{
	if (m_v->size() == m_N)
		throw std::runtime_error(std::string("Max size reached"));
	m_v->push_back(num);
}

void Span::addNumber(std::vector<int> vct)
{
	if (vct.size() == 0)
		return;
	else if (m_N < vct.size())
		throw std::runtime_error(std::string("Max size reached"));
	m_v->insert(m_v->begin(), vct.begin(), vct.end());
}

int Span::longestSpan(void)
{
	int max;
	int min;

	if (m_v->size() < 2)
		throw std::runtime_error(std::string("Not enough numbers"));
	max = *std::max_element(m_v->begin(), m_v->end());
	min = *std::min_element(m_v->begin(), m_v->end());

	return (max - min);
}

int Span::shortestSpan(void)
{
	std::vector<int> sortedV;
	int	shortspan;
	int temp;
	
	if (m_v->size() < 2)
		throw std::runtime_error(std::string("Not enough numbers"));
	sortedV.insert(sortedV.begin(), m_v->begin(), m_v->end());
	std::sort(sortedV.begin(), sortedV.end());
	shortspan = sortedV[1] - sortedV[0];
	for(unsigned long i = 1; i < sortedV.size() - 2; i++)
	{
		temp = sortedV[i + 1] - sortedV[i];
		if (temp < shortspan)
			shortspan = temp;
	}
	return (shortspan);
}