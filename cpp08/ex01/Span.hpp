/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:26:37 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/12 17:33:46 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span(int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

		void addNumber(int num);
		void addNumber(std::vector<int> vct);
		int shortestSpan(void);				
		int longestSpan(void);
		
	private:
		unsigned int m_N;
		std::vector<int> *m_v;
		Span();
};

#endif