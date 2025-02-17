/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:54:47 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/17 16:37:02 by rpandipe         ###   ########.fr       */
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

void PmergeMe::insertLoser(std::vector<int>& winner, std::vector<int>& loser, std::vector<int>& v)
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
			if (v[b] < v[winner[j]])
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
			if  (v[b] < v[winner[j]])
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

void PmergeMe::sortLoser(std::vector<int> &winner, std::vector<int>& loser)
{
	std::vector<int> subloser(loser);

	for (size_t i=0; i < winner.size(); i++)
	{
		int j =0;
		
		if (winner[i] < static_cast<int>(loser.size()))
		{
			loser[j] = subloser[winner[i]];
			j++;
		}
	}
}

void PmergeMe::sortWinner(std::vector<int> &winner, std::vector<int>& v)
{
	std::vector<int> subloser;
	std::vector<int> subwinner(winner);
	int n = winner.size();
	
	if (n > 3)
	{
		for (size_t i = 0; i + 1  < winner.size(); i++)
		{
			subloser.push_back(v[winner[i]] > v[winner[i + 1]] ? winner[i+1] : winner[i]);
			winner.erase(winner[i] > winner[i + 1] ? winner.begin() + i + 1 : winner.begin() + i);
		}

		std::cout << "Winner before sort: ";
		for (size_t k = 0; k < winner.size(); k++)
			std::cout << winner[k] << " ";
		std::cout << std::endl;
		

		sortWinner(winner, v);

		std::cout << "Winner after sort: ";
		for (size_t k = 0; k < winner.size(); k++)
			std::cout << winner[k] << " ";
		std::cout << std::endl;

		std::cout << "Sorted Subwinner: ";
		for (size_t k = 0; k < winner.size(); k++)
			std::cout << v[winner[k]] << " ";
		std::cout << std::endl;
		

		std::cout << "Loser before sort: ";
		for (size_t k = 0; k < subloser.size(); k++)
			std::cout << subloser[k] << " ";
		std::cout << std::endl;
		
		sortLoser(winner, subloser);
		
		std::cout << "Loser after sort: ";
		for (size_t k = 0; k < subloser.size(); k++)
			std::cout << subloser[k] << " ";
		std::cout << std::endl;
		
		insertLoser(winner, subloser, v);
		std::cout << "Sorted Subwinner (after insertion): ";
		for (size_t k = 0; k < winner.size(); k++)
			std::cout << v[winner[k]] << " ";
		std::cout << std::endl;
	}
	else
	{
		if ((n == 2) && (v[winner[0]] > v[winner[1]]))
			std::swap(winner[0], winner[1]);
		else if (n == 3)
		{
			if (v[winner[0]] > v[winner[1]]) std::swap(winner[0], winner[1]);
			if (v[winner[1]] > v[winner[2]]) std::swap(winner[1], winner[2]);
			if (v[winner[0]] > v[winner[1]]) std::swap(winner[0], winner[1]);
		}
	}
}

void PmergeMe::sortVector(std::vector<int> &v)
{
	int n = v.size();
	int lmt = n % 2 == 0 ? n : n - 1;
	std::vector<int> winner;
	std::vector<int> loser;

	/*if (n <= 3)
	{
		sortWinner(v);
		return ;
	}*/
	for (int i = 0; i < lmt; i = i + 2)
	{
		winner.push_back(v[i] > v[i+1] ? i : i+1);
		loser.push_back(v[i] > v[i+1] ? i+1 : i);
	}
	if (n != lmt)
		loser.push_back(n - 1);
	
	std::cout << "Winner: ";
	for (size_t k = 0; k < winner.size(); k++)
		std::cout << winner[k] << " ";
	std::cout << std::endl;

	std::cout << "Loser: ";
	for (size_t k = 0; k < loser.size(); k++)
		std::cout << loser[k] << " ";
	std::cout << std::endl;
	
	sortWinner(winner, v);
	sortLoser(winner, loser);
	insertLoser(winner, loser, v);
	std::vector<int> i_copy (v);
	for(size_t i= 0; i < v.size(); i++)
		v[i] = i_copy[winner[i]];
}