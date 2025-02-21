/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:28:09 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/17 16:07:09 by rpandipe         ###   ########.fr       */
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
		void sortWinner(std::vector<int>& winner, std::vector<int>& v);
		void sortLoser(std::vector<int>& winner,  std::vector<int>& loser);
		void insertLoser(std::vector<int>& winner, std::vector<int>& loser, std::vector<int>& v);
};

#endif