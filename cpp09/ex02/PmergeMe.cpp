/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:59:14 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/21 09:36:42 by rpandipe         ###   ########.fr       */
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
	for (int k = i; k < lim; k++)
		subchain.push_back(winner[k]);
}

void PmergeMe::insertLoser(std::vector<int>& subchain, int c)
{
	size_t n = subchain.size();
	int group_num = n / c;
	int *seq;
	int group, start, end, b, val;
	std::vector<int>::iterator it;
	
	seq = getJacobsthal(group_num);
	for (int i = 0; i < group_num; i++)
	{
		group = seq[i] % group_num;
		start = group * c;
		end = start + c;
		b = subchain.at(start + 1);
		it = std::lower_bound(subchain.begin() + start, subchain.begin() + end, b);
		for (int k = start; k < end; k++)
		{
			val = subchain[k];
			subchain.erase(subchain.begin() + start);
			subchain.insert(it, val);
		}
	}
	delete[] seq;
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
	insertLoser(chain, 2);
	v.clear();
	v.assign(chain.begin(), chain.end());
}