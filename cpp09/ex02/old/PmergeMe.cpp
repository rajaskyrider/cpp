/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:02:23 by rpandipe          #+#    #+#             */
/*   Updated: 2025/03/02 22:42:17 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

bool PmergeMe::comparePairs(const std::pair<int, int> &a, const std::pair<int, int> &b) 
{
	return a.first < b.first;
}

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

void PmergeMe::insertLoser(std::vector<std::pair<int, int> > &chain, int c)
{
	size_t n = chain.size() / c;
	int *seq = getJacobsthal(n);
	std::vector<std::pair<int, int> >::iterator new_pos, old_pos, pair_pos;
	std::vector<int> idx;
	std::vector<std::pair<int, int> > winner, loser, copy;

	winner.reserve(chain.size()); // reserve capacity to stop reallocation when inserting loser. so old_pos is automatically shifted right.
	for (size_t i = 0; i  < chain.size(); i += c)
		for (int j = 0; j < c; j++)
			winner.push_back(chain[i + j]);

	for(size_t i = c - 1; i  < chain.size(); i += c)
		for (int j = 0; j < c; j++)
			loser.push_back(chain[i + j]);

	copy.assign(winner.begin(), winner.end());

	for (int i = 0; i < loser.size(); i++)
		idx.push_back(i);
	for (size_t i = 0; seq[i] < loser.size(); i++)
	{
		old_pos = loser.begin() + seq[i] + c;
		pair_pos = std::find(winner.begin() + seq[i] + c , winner.end(), copy[seq[i] + c]);
		new_pos = std::lower_bound(winner.begin(), pair_pos, old_pos->first, PmergeMe::comparePairs);
		for (int j = 0; j < c; j++)
			winner.insert(new_pos, *(old_pos + j));
		idx.erase(idx.begin() + seq[i] - i);
	}
	for (std::vector<int>::iterator it = idx.begin(); it != idx.end(); it++)
	{
		old_pos = loser.begin() + *it + c;
		pair_pos = std::find(winner.begin() + *it + c , winner.end(), copy[*it + c]);
		new_pos = std::lower_bound(winner.begin(), pair_pos, old_pos->first, PmergeMe::comparePairs);
		for (int j = 0; j < c; j++)
			winner.insert(new_pos, *(old_pos + j));
	}
}

void PmergeMe::sortLoser(std::vector<std::pair<int, int> > &winner, std::vector<int> &res)
{
	res.clear();
	for (std::vector<std::pair<int, int> >::iterator it = winner.begin(); it != winner.end(); it++)
	{
		res.push_back(it->first);
		res.push_back(it->second);
	}
	res.reserve(res.size() * 2);
	for (size_t i = 0; i < res.size(); i+=2)
	{
		
	}
}

void PmergeMe::sortWinner(std::vector<std::pair<int, int> > &winner, int c)
{
	size_t n = winner.size() / c + ((c > 1 && winner.size() / 2 == 0) ? 0 : 1);

	if (n > 3)
	{
		for (size_t i = 0; i  < winner.size() - c; i += 2 * c)
		{
			if (winner[i].first > winner[i + c].first)
				std::swap(winner[i], winner[i + c]);
		}
		sortWinner(winner, c * 2);
		if (c != 1)
			insertLoser(winner, c);
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
	
	chain.reserve(chain.size() * 2); // reserve double capacity to stop reallocation when inserting loser. so old_pos is automatically shifted right.
	sortWinner(chain, 1);
	sortLoser(chain, v);
}