/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:28:09 by rpandipe          #+#    #+#             */
/*   Updated: 2025/03/04 22:11:30 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<sstream>


class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		void sortVector(int argc, char **argv);
		void sortdeque(int argc, char **argv);

	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		int getJacobsthal(int n);
		void getVector(int argc, char **argv, std::vector<int> &v);
		void getdeque(int argc, char **argv, std::deque<int> &v);
		void sortWinner(std::vector<int> &winner, int c);
		void sortWinner(std::deque<int> &winner, int c);
		void sortLoser(std::vector<int> &chain, int c, std::vector<int>::iterator start, std::vector<int>::iterator end);
		void sortLoser(std::deque<int> &chain, int c, std::deque<int>::iterator start, std::deque<int>::iterator end);
		void insertLoser(std::vector<int> &winner, std::vector<int> &loser, int val_odd, std::vector<int> &ans, std::vector<int> &chain, bool is_odd, int c);
		void insertLoser(std::deque<int> &winner, std::deque<int> &loser, int val_odd, std::deque<int> &rem, std::deque<int> &chain, bool is_odd, int c);
};

#endif