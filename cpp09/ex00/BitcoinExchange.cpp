/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:49:51 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/15 13:15:37 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	m_createDB();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : m_exchange(other.m_exchange)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		m_exchange = other.m_exchange;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::m_createDB()
{
	std::ifstream	ifs("data.csv");
	std::string		field;
	std::string		key;
	double			value;
	size_t			commapos;

	if (!ifs)
		throw std::runtime_error("Error: Unable to open the database file");
	std::getline(ifs, field); //skip first line
	while (std::getline(ifs, field))
	{
		commapos = field.find(',');
		if (commapos == std::string::npos)
			throw std::invalid_argument("Invalid line argument: " + field);
		key = field.substr(0, commapos);
		std::stringstream ss(field.substr(commapos + 1));
		if (!(ss >> value))
			throw std::runtime_error("Conversion of key failed for: " + key);
		if (value > std::numeric_limits<double>::max())
			throw std::overflow_error("Value exceeds max for key: " + key);
		m_exchange[key] = value;
	}
	//for(std::map<std::string, double>::iterator it = m_exchange.begin(); it != m_exchange.end(); it++)
	//	std::cout << it->first << " " << it->second << std::endl;
}

bool BitcoinExchange::isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& edate)
{
	int year, month, day, maxdays;
	char sep1, sep2;
	std::stringstream ss(edate);

	if (!(ss >> year >> sep1 >> month >> sep2 >> day) || (sep1 != '-' ) || (sep2 != '-'))
		return (false);
 	if (month > 12 || month < 1)
		return (false);
	switch(month)
	{
		case 4: case 6: case 9: case 11: maxdays = 30; break;
		case 2: maxdays = isLeapYear(year) ? 29 : 28; break;
		default: maxdays = 31;
	}
	return ((day > 0) && (day <= maxdays));
}

void BitcoinExchange::convert(const char* file)
{
	std::ifstream	ifs(file);
	double			rate;
	double			amt;
	std::string		field;
	size_t			seppos;
	std::string		edate;

	if (m_exchange.empty())
		throw std::runtime_error("Exchange is empty");
	if (!ifs)
		throw std::runtime_error("could not open file.");
	std::getline(ifs, field); // skip header
	while(std::getline(ifs, field))
	{
		seppos = field.find('|');
		if (seppos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << field << std::endl;
			continue ;
		}
		edate = field.substr(0, seppos);
		if (!isValidDate(edate))
		{
			std::cerr << "Error: bad input => " << field << std::endl;
			continue ;
		}
		std::map<std::string, double>::iterator it = m_exchange.lower_bound(edate);
		if (it == m_exchange.begin() && it->first != edate)
		{
			std::cerr << "Error: No exchange rate available for => " << edate << std::endl;
			continue ;
		}
		if (it == m_exchange.end() || it->first != edate)
			--it;	
		rate = it->second;
		std::stringstream ss(field.substr(seppos + 1));
		if (!(ss >> amt))
			std::cerr << "Error: bad input => " << field << std::endl;
		else if (amt < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (amt > 1000)
			std::cerr << "Error: too large a number" << std::endl;
		else
			std::cout << edate << " => " << amt << " = " 
          	<< std::setprecision(2) << amt * rate 
         	<< std::endl;
	}
}