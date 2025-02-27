/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:02:23 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/27 18:46:31 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

int* PmergeMe::getJacobsthal(int n)
{
	int *seq = new int[n];
	seq[0] = 1;
	if (n > 1)
		seq[1] = 3;

	for(int i = 2; i < n; i++)
		seq[i] = seq[i - 1] + (2 * seq[i - 2]);
	return seq;
}

void PmergeMe::sortWinner(std::vector<std::pair<int, int> > &winner, int c)
{
	size_t n = winner.size() / c + (c > 1 && n / 2 == 0) ? 0 : 1;

	if (n > 3)
	{
		for (size_t i = 0; i  < winner.size() - 1; i += c)
		{
			if (winner[i].first > winner[i + c].first)
				winner.swap(i , i+c);
		}
	}
}

void PmergeMe::sortVector(std::vector<int> &v)
{
	std::vector<std::pair<int, int> > chain;
	int n = v.size();
	int limit = n % 2 == 0 ? n : n - 1;

	if (n <= 3)
	{
		//TODO
		return ;
	}
	for (int i = 0; i < limit; i = i + 2)
	{
		if (v[i] > v[i+1])
			chain.push_back(std::pair<int, int>(v[i],v[i+1]));
		else
			chain.push_back(std::pair<int, int>(v[i+1],v[i]));
	}
	if (n != limit)
		chain.push_back(std::pair<int, int>(-1, v[n -1]));
	
	sortWinner(chain, 1);
	insertLoser(chain, 1);
}