/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:21:09 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/25 09:56:25 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

// Generate Jacobsthal sequence for insertion order
int* PmergeMe::getJacobsthal(int n) {
    int* seq = new int[n];
    seq[0] = 0; // Jacobsthal(0) = 0
    if (n > 1) seq[1] = 1; // Jacobsthal(1) = 1
    for (int i = 2; i < n; i++) {
        seq[i] = seq[i - 1] + 2 * seq[i - 2];
    }
    return seq;
}

// Main sorting function for the vector
void PmergeMe::sortVector(std::vector<int>& v) {
    int n = v.size();
    if (n <= 1) return;

    // Pairing phase
    std::vector<int> winners;
    std::vector<int> losers;
    int i;
    for (i = 0; i < n - 1; i += 2) {
        if (v[i] > v[i + 1]) {
            winners.push_back(v[i]);
            losers.push_back(v[i + 1]);
        } else {
            winners.push_back(v[i + 1]);
            losers.push_back(v[i]);
        }
    }
    if (i < n) {
        // Odd element, treat as loser with sentinel winner -1
        winners.push_back(-1);
        losers.push_back(v[i]);
    }

    // Recursively sort the winners
    sortWinner(winners);

    // Build the initial chain with sorted winners
    std::vector<int> chain(winners.begin(), winners.end());

    // Insert losers into the chain
    insertLosers(chain, losers, winners);

    // Assign the sorted chain back to the input vector
    v.assign(chain.begin(), chain.end());
}

// Recursively sort the winners
void PmergeMe::sortWinner(std::vector<int>& winners) {
    int n = winners.size();
    if (n <= 3) {
        // Base case: sort small number of elements
        if (n == 2) {
            if (winners[0] > winners[1]) {
                std::swap(winners[0], winners[1]);
            }
        } else if (n == 3) {
            // Simple sort for 3 elements
            if (winners[0] > winners[1]) std::swap(winners[0], winners[1]);
            if (winners[1] > winners[2]) std::swap(winners[1], winners[2]);
            if (winners[0] > winners[1]) std::swap(winners[0], winners[1]);
        }
        return;
    }

    // Pairing winners
    std::vector<int> newWinners;
    std::vector<int> newLosers;
    int i;
    for (i = 0; i < n - 1; i += 2) {
        if (winners[i] > winners[i + 1]) {
            newWinners.push_back(winners[i]);
            newLosers.push_back(winners[i + 1]);
        } else {
            newWinners.push_back(winners[i + 1]);
            newLosers.push_back(winners[i]);
        }
    }
    if (i < n) {
        // Odd element
        newWinners.push_back(winners[i]);
    }

    // Recursively sort new winners
    sortWinner(newWinners);

    // Build subchain with sorted new winners
    std::vector<int> subchain(newWinners.begin(), newWinners.end());

    // Insert new losers into subchain
    insertLosers(subchain, newLosers, newWinners);

    // Assign back to winners
    winners.assign(subchain.begin(), subchain.end());
}

// Insert losers into the chain with binary search using the winner as upper bound
void PmergeMe::insertLosers(std::vector<int>& chain, const std::vector<int>& losers, const std::vector<int>& winners) {
    int n = losers.size();
    if (n == 0) return;

    // Generate Jacobsthal sequence for insertion order
    int* jacobsthal = getJacobsthal(n);
    std::vector<bool> inserted(n, false);

    // Insert losers in Jacobsthal order
    for (int k = 0; k < n; ++k) {
        int idx = jacobsthal[k] % n;
        while (inserted[idx]) {
            idx = (idx + 1) % n;
        }
        int loser = losers[idx];
        int winner = winners[idx];

        // Find the position of the winner in the chain
        std::vector<int>::iterator winnerPos = std::find(chain.begin(), chain.end(), winner);
        if (winnerPos == chain.end()) {
            // If winner is -1 (sentinel), insert at the end
            chain.push_back(loser);
        } else {
            // Binary search up to the winner's position as the upper bound
            std::vector<int>::iterator it = std::lower_bound(chain.begin(), winnerPos + 1, loser);
            chain.insert(it, loser);
        }
        inserted[idx] = true;
    }
    delete[] jacobsthal;
}