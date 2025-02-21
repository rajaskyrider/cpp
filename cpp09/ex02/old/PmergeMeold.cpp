/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:54:47 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/17 10:45:32 by rpandipe         ###   ########.fr       */
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

void PmergeMe::insertLoser(std::vector<int>& winner, std::vector<int>& loser)
{
	int sn, b, count = 0;
	int *seq;
	size_t j;

	sn = loser.size();
	seq = getJacobsthal(sn);
	for (int i = 0; i < sn; i++)
	{
		if (seq[i] >= sn)
			break;
		b = loser.at(seq[i]);
		for (j = 0; j < winner.size(); j++)
		{
			if (b < winner[j])
			{
				winner.insert(winner.begin() + j, b);
				count++;
				break;
			}
		}
	}
	for (int i = count - 1; i >= 0; i--)
		loser.erase(loser.begin() + seq[i]);
	while (loser.size() > 0)
	{
		b = loser[0];
		loser.erase(loser.begin());
		for (j = 0; j < winner.size(); j++)
		{
			if  (b < winner[j])
			{
				winner.insert(winner.begin() + j, b);
				break ;
			}
			else if (j == winner.size() - 1)
			{
				winner.push_back(b);
				break ;
			}
		}
	}
	delete[] seq;
}

void PmergeMe::sortWinner(std::vector<int> &winner)
{
	std::vector<int> subloser;
	int n = winner.size();
	
	if (n > 3)
	{
		for (size_t i = 0; i + 1  < winner.size(); i++)
		{
			subloser.push_back(winner[i] > winner[i + 1] ? winner[i+1] : winner[i]);
			winner.erase(winner[i] > winner[i + 1] ? winner.begin() + i + 1 : winner.begin() + i);
		}
		sortWinner(winner);
		insertLoser(winner, subloser);
	}
	else
	{
		if ((n == 2) && (winner[0] > winner[1]))
			std::swap(winner[0], winner[1]);
		else if (n == 3)
		{
			if (winner[0] > winner[1]) std::swap(winner[0], winner[1]);
			if (winner[1] > winner[2]) std::swap(winner[1], winner[2]);
			if (winner[0] > winner[1]) std::swap(winner[0], winner[1]);
		}
	}
}

void PmergeMe::sortVector(std::vector<int> &v)
{
	int n = v.size();
	int lmt = n % 2 == 0 ? n : n - 1;
	std::vector<int> winner;
	std::vector<int> loser;

	if (n <= 3)
	{
		sortWinner(v);
		return ;
	}
	for (int i = 0; i < lmt; i = i + 2)
	{
		winner.push_back(v[i] > v[i+1] ? v[i] : v[i+1]);
		loser.push_back(v[i] > v[i+1] ? v[i+1] : v[i]);
	}
	if (n != lmt)
		loser.push_back(v[n - 1]);
	sortWinner(winner);
	insertLoser(winner, loser);
	v.clear();
	v.assign(winner.begin(), winner.end());
}