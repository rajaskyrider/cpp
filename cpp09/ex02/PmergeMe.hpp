/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:28:09 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/25 09:56:38 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>


class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		void sortVector(std::vector<int> &v);
		void sortDeque(std::deque<int> d);

	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		int* getJacobsthal(int n);
		void sortWinner(std::vector<int>& winners);
		void insertLosers(std::vector<int>& chain, const std::vector<int>& losers, const std::vector<int>& winners);
		void insertWinner(int i, int lim, std::vector<int> &winner, std::vector<int> &subchain);
};

#endif