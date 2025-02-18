/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:59:14 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/18 15:54:03 by rpandipe         ###   ########.fr       */
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

void PmergeMe::insertWinner(int i, int lim, std::vector<int> &winner, std::vector<int> &subchain)
{
	for (int i; i < lim; i++)
		subchain.push_back(winner[i]);
}

void PmergeMe::insertLoser(std::vector<int>& subchain, int c)
{
	size_t n = subchain.size();
	int *seq;
	
	seq = getJacobsthal(n / 2);
	for (int i = 1; i < n; i = i + c)
	{
		
	}
}

void PmergeMe::sortWinner(std::vector<int> &winner, int c)
{
	std::vector<int> subchain;
	size_t n = winner.size() / c;
	
	if (n > 3)
	{
		for (size_t i = 0; i + c  < winner.size(); i = i + (2 * c))
		{
			if (winner[i] > winner[i + c])
				insertWinner(i, i + (2 * c), winner, subchain);
			else
			{
				insertWinner(i + c, i + (2 * c), winner, subchain);
				insertWinner(i, i + c, winner, subchain);
			}
		}
		sortWinner(subchain, c * 2);
		insertLoser(subchain, c);
	}
	else
	{
		if ((n == 2) && (winner[0] > winner[c]))
		{
			insertWinner(c, c + (2 * c), winner, subchain);
			insertWinner(0, (2 * c), winner, subchain);
		}
		else if (n == 3)
		{
			if (winner[0] > winner[c])
			{
				insertWinner(c, c + (2 * c), winner, subchain);
				insertWinner(0, c, winner, subchain);
			}
			else
				insertWinner(0 , 2 * c, winner, subchain);
			if (winner[c] > winner[c * 2])
			{
				insertWinner(c * 2, (c * 2) + (2 * c), winner, subchain);
				insertWinner(c, c * 2, winner, subchain);
			}
			if (winner[0] > winner[c])
			{
				for (int i = 0; i < c; i++)
					std::swap(subchain[i], subchain[i+c]);
			}
		}
	}
	winner.clear();
	winner.assign(subchain.begin(), subchain.end());
}


void PmergeMe::sortVector(std::vector<int> &v)
{
	int n = v.size();
	int lmt = n % 2 == 0 ? n : n - 1;
	std::vector<int> chain;

	/*if (n <= 3)
	{
		sortWinner(v);
		return ;
	}*/
	for (int i = 0; i < lmt; i = i + 2)
	{
		if (v[i] > v[i+1])
		{
			chain.push_back(v[i]);
			chain.push_back(v[i+1]);
		}
		else
		{
			chain.push_back(v[i+1]);
			chain.push_back(v[i]);
		}
	}
	if (n != lmt)
	{
		chain.push_back(-1);
		chain.push_back(v[n-1]);
	}
	sortWinner(chain, 2);
	//insertLoser(winner, loser);
	v.clear();
	v.assign(chain.begin(), chain.end());
}