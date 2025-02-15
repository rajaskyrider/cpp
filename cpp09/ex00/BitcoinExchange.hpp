/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:41:57 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/15 00:30:13 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <map>
#include <fstream> 
#include <sstream>
#include <limits>
#include <iomanip>
#include <stdexcept>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		void convert(const char* file);
	
	private:
		std::map<std::string, double> m_exchange;
		void m_createDB();
		bool isValidDate(const std::string& edate);
		bool isLeapYear(int year);
};

#endif