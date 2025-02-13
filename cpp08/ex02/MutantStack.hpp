/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:26:10 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/13 17:13:54 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>

template <typename T = int, typename container = std::deque<T> >
class MutantStack: public std::stack<T, container>
{
	public:
		MutantStack():std::stack<T, container>(){};
		MutantStack(const MutantStack &other):std::stack<T,container>(other){};
		MutantStack& operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T,container>::operator=(other);
			return *this;
		}
		~MutantStack(){};
		
		typedef typename container::iterator iterator;
		
		iterator begin(){return this->c.begin();};
		iterator end(){return this->c.end();};
};

#endif