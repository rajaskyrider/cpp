/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:23:28 by rpandipe          #+#    #+#             */
/*   Updated: 2025/03/04 22:16:12 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

void PmergeMe::insertLoser(std::vector<int> &winner, std::vector<int> &loser, int val_odd, std::vector<int> &rem, std::vector<int> &chain, bool is_odd, int c)
{
	std::vector<int>::iterator pos;
	std::vector<int> ans;
	size_t jc = 3, cnt = 0, idx, sub = 0;

	if (loser.size() == 1)
	{
		pos = std::upper_bound(winner.begin(), winner.end(), *loser.begin());
		winner.insert(pos, *loser.begin());
	}
	else if (loser.size()  > 1)
	{
		while(!loser.empty())
		{
			idx = getJacobsthal(jc) - getJacobsthal(jc -1);
			if (idx > loser.size())
				idx = loser.size();
			sub = 0;
			while (idx)
			{
				pos = winner.begin();
				if (getJacobsthal(jc + cnt) - sub <= winner.size())
					pos = winner.begin() + getJacobsthal(jc + cnt) - sub;
				else
					pos = winner.end();
				pos = std::upper_bound(winner.begin(), pos, *(loser.begin() + idx - 1));
				winner.insert(pos, *(loser.begin() + idx - 1));
				loser.erase(loser.begin() + idx - 1);
				idx--;
				sub++;
				cnt++;
			}
			jc++;
		}
	}
	if(is_odd)
	{
		pos = std::upper_bound(winner.begin(), winner.end(), val_odd);
		winner.insert(pos, val_odd);
	}
	for (std::vector<int>::iterator i = winner.begin(); i != winner.end(); i++)
	{
        std::vector<int>::iterator it = std::find(chain.begin(), chain.end(), *i);
        ans.insert(ans.end(), it - (c - 1), it + 1);
    }
	ans.insert(ans.end(), rem.begin(), rem.end());
	chain = ans;
}

void PmergeMe::insertLoser(std::deque<int> &winner, std::deque<int> &loser, int val_odd, std::deque<int> &rem, std::deque<int> &chain, bool is_odd, int c)
{
	std::deque<int>::iterator pos;
	std::deque<int> ans;
	size_t jc = 3, cnt = 0, idx, sub = 0;

	if (loser.size() == 1)
	{
		pos = std::upper_bound(winner.begin(), winner.end(), *loser.begin());
		winner.insert(pos, *loser.begin());
	}
	else if (loser.size()  > 1)
	{
		while(!loser.empty())
		{
			idx = getJacobsthal(jc) - getJacobsthal(jc -1);
			if (idx > loser.size())
				idx = loser.size();
			sub = 0;
			while (idx)
			{
				pos = winner.begin();
				if (getJacobsthal(jc + cnt) - sub <= winner.size())
					pos = winner.begin() + getJacobsthal(jc + cnt) - sub;
				else
					pos = winner.end();
				pos = std::upper_bound(winner.begin(), pos, *(loser.begin() + idx - 1));
				winner.insert(pos, *(loser.begin() + idx - 1));
				loser.erase(loser.begin() + idx - 1);
				idx--;
				sub++;
				cnt++;
			}
			jc++;
		}
	}
	if(is_odd)
	{
		pos = std::upper_bound(winner.begin(), winner.end(), val_odd);
		winner.insert(pos, val_odd);
	}
	for (std::deque<int>::iterator i = winner.begin(); i != winner.end(); i++)
	{
        std::deque<int>::iterator it = std::find(chain.begin(), chain.end(), *i);
        ans.insert(ans.end(), it - (c - 1), it + 1);
    }
	ans.insert(ans.end(), rem.begin(), rem.end());
	chain = ans;
}

void PmergeMe::sortLoser(std::vector<int> &chain, int c, std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	std::vector<int> winner , loser, rem;
	bool is_odd = (chain.size() / c) % 2 == 1;
	int val_odd = 0;

	winner.push_back(*(start + c - 1)); // a1
	winner.push_back(*(start + (2 * c) - 1)); // b1

	for (std::vector<int>::iterator it = start + (2 * c); it < end; it += c)
	{
		loser.push_back(*(it + c - 1)); // a
		it += c;
		winner.push_back(*(it + c - 1)); // b
	}
	if (is_odd)
		val_odd = *(end + c - 1);
	rem.insert(rem.end(), end + (c * is_odd), chain.end());
	if (is_odd || !loser.empty())
		insertLoser(winner, loser, val_odd, rem, chain, is_odd, c);
}

void PmergeMe::sortLoser(std::deque<int> &chain, int c, std::deque<int>::iterator start, std::deque<int>::iterator end)
{
	std::deque<int> winner , loser, rem;
	bool is_odd = (chain.size() / c) % 2 == 1;
	int val_odd = 0;

	winner.push_back(*(start + c - 1)); // a1
	winner.push_back(*(start + (2 * c) - 1)); // b1

	for (std::deque<int>::iterator it = start + (2 * c); it < end; it += c)
	{
		loser.push_back(*(it + c - 1)); // a
		it += c;
		winner.push_back(*(it + c - 1)); // b
	}
	if (is_odd)
		val_odd = *(end + c - 1);
	rem.insert(rem.end(), end + (c * is_odd), chain.end());
	if (is_odd || !loser.empty())
		insertLoser(winner, loser, val_odd, rem, chain, is_odd, c);
}

void PmergeMe::sortWinner(std::vector<int> &winner, int c)
{
	int n = winner.size() / c;
	bool is_odd = n % 2 == 1;
	std::vector<int>::iterator start, end;

	if (n < 2)
		return ;
	start = winner.begin();
	end = winner.begin() + ((c * n) - (is_odd * c));
	for (std::vector<int>::iterator it = start; it < end; it += 2 * c)
	{
		if (*(it + c - 1) > *(it + (c * 2) - 1))
		{
			for (int j = 0; j < c; j++)
				std::swap(*(it + j), *(it + j + c));
		}
	}
	sortWinner(winner, c * 2);
	sortLoser(winner, c, start, end);
}

void PmergeMe::sortWinner(std::deque<int> &winner, int c)
{
	int n = winner.size() / c;
	bool is_odd = n % 2 == 1;
	std::deque<int>::iterator start, end;

	if (n < 2)
		return ;
	start = winner.begin();
	end = winner.begin() + ((c * n) - (is_odd * c));
	for (std::deque<int>::iterator it = start; it < end; it += 2 * c)
	{
		if (*(it + c - 1) > *(it + (c * 2) - 1))
		{
			for (int j = 0; j < c; j++)
				std::swap(*(it + j), *(it + j + c));
		}
	}
	sortWinner(winner, c * 2);
	sortLoser(winner, c, start, end);
}

void PmergeMe::getVector(int argc, char **argv, std::vector<int> &v)
{
	int n;
	std::stringstream ss;

	for (int i = 1; i < argc; i++)
	{
		ss.clear();
		ss << argv[i];
		if (!(ss >> n))
			throw std::invalid_argument("Invalid inputs");
		if (n < 0)
			throw std::invalid_argument("Negative numbers are not allowed");
		if (v.end() != std::find(v.begin(), v.end(), n))
			throw std::invalid_argument("Duplicates are not allowed");
		v.push_back(n);
	}
}

void PmergeMe::getdeque(int argc, char **argv, std::deque<int> &v)
{
	int n;
	std::stringstream ss;

	for (int i = 1; i < argc; i++)
	{
		ss.clear();
		ss << argv[i];
		if (!(ss >> n))
			throw std::invalid_argument("Invalid inputs");
		if (n < 0)
			throw std::invalid_argument("Negative numbers are not allowed");
		if (v.end() != std::find(v.begin(), v.end(), n))
			throw std::invalid_argument("Duplicates are not allowed");
		v.push_back(n);
	}
}

void PmergeMe::sortVector(int argc, char **argv)
{
	std::vector<int> m;

	clock_t start, end;
	start = clock();
	getVector(argc, argv, m);
	std::cout << "Unsorted Array: ";
	for (size_t i = 0; i < m.size(); i++)
			std::cout << m[i] << " ";
	std::cout << std::endl;
	sortWinner(m, 1);
	end = clock();
	std::cout << "Sorted Array: ";
	for (size_t i = 0; i < m.size(); i++)
			std::cout << m[i] << " ";
	std::cout << std::endl;
	double elapsed_time_micro = static_cast<double>(end - start) * (1000000.0 / CLOCKS_PER_SEC);
	std::cout << "Execution time with std::vector for " << argc - 1 << " number : " << elapsed_time_micro << " µs" << std::endl;
}

void PmergeMe::sortdeque(int argc, char **argv)
{
	std::deque<int> m;

	clock_t start, end;
	start = clock();
	getdeque(argc, argv, m);
	std::cout << "Unsorted Array: ";
	for (size_t i = 0; i < m.size(); i++)
			std::cout << m[i] << " ";
	std::cout << std::endl;
	sortWinner(m, 1);
	end = clock();
	std::cout << "Sorted Array: ";
	for (size_t i = 0; i < m.size(); i++)
			std::cout << m[i] << " ";
	std::cout << std::endl;
	double elapsed_time_micro = static_cast<double>(end - start) * (1000000.0 / CLOCKS_PER_SEC);
	std::cout << "Execution time with std::deque for " << argc - 1 << " number : " << elapsed_time_micro << " µs" << std::endl;
}

int PmergeMe::getJacobsthal(int k) 
{
    return round((pow(2, k + 1) + pow(-1, k)) / 3);
}
