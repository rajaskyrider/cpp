/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:03:44 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/30 16:18:25 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

namespace ConvertUtils
{
	bool checkPseudo(std::string str)
	{
		if (str == "-inff" || str == "+inff" || str == "+inf" || str =="-inf"
			|| str == "nan" || str == "nanf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		if (str == "-inff" || str =="-inf")
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			return (true);
		}
		if (str == "+inff" || str =="+inf")
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			return (true);
		}
		if (str == "nanf" || str =="nan")
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return (true);
		}
		return (false);
	}

	void convertFloat(std::string str)
	{
		double f = 0.0;
		char remaining;
		
		if (str.find("f") == std::string::npos)
			return ;
		std::stringstream ss(str.substr(0, str.length() - 1));
		if (!(ss >> f))
			throw (std::invalid_argument("Invalid Inputs"));
		if (ss >> remaining)
			throw (std::invalid_argument("Unexpected character in input"));
		if (f > std::numeric_limits <float>::max() || f < -std::numeric_limits <float>::max())
			throw (std::overflow_error("Float overflow"));

		std::cout << "char: ";
		if (std::isprint(static_cast<char>(f)))
			std::cout << "'" << static_cast<char>(f) << "'";
		else
			std::cout << "Not printable";
		std::cout << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		if (f == static_cast<int>(f))
        	std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
		std::cout << "double: " << f << std::endl;
	}

	void convertDouble(std::string str)
	{
		long double d = 0.0;
		char remaining;
		
		if (str.find("f") != std::string::npos)
			return ;

		std::stringstream ss(str);
		if (!(ss >> d))
			throw (std::invalid_argument("Invalid Inputs"));
		if (ss >> remaining)
			throw (std::invalid_argument("Unexpected character in input"));
		if (d > std::numeric_limits <double>::max() || d < -std::numeric_limits <double>::max())
			throw (std::overflow_error("Double overflow"));

		std::cout << "char: ";
		if (std::isprint(static_cast<char>(d)))
			std::cout << "'" << static_cast<char>(d) << "'";
		else
			std::cout << "Not printable";
		std::cout << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		if (d == static_cast<int>(d))
        	std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	}
	
	void convertInteger(std::string str)
	{
		long int n = 0;
		char remaining;
		

		std::stringstream ss(str);
		if (!(ss >> n))
			throw (std::invalid_argument("Invalid Inputs"));
		if (ss >> remaining)
			throw (std::invalid_argument("Unexpected character in input"));
		if (n > std::numeric_limits <int>::max() || n < -std::numeric_limits <int>::max())
			throw (std::overflow_error("Integer overflow"));

		std::cout << "char: ";
		if (std::isprint(static_cast<char>(n)))
			std::cout << "'" << static_cast<char>(n) << "'";
		else
			std::cout << "Not printable";
		std::cout << std::endl;
		std::cout << "int: " << static_cast<int>(n) << std::endl;
		if (n == static_cast<int>(n))
        	std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) << std::endl;
	}

	void convertCharacter(std::string str)
	{
		char c = 0;

		if (str.length() != 1)
		{
			std::cout << "Invalid arguments" << std::endl;
			return ;
		}
		try
		{
			c = static_cast<char>(str[0]);
			std::cout << "char: ";
			if (std::isprint(c))
				std::cout << "'" << c << "'";
			else
				std::cout << "Not printable";
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			if (c == static_cast<int>(c))
        		std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void ScalarConverter::convert(std::string str)
{
	try
	{
		if (ConvertUtils::checkPseudo(str))
			return ;
		if (str.find(".") != std::string::npos)
		{
			ConvertUtils::convertFloat(str);
			ConvertUtils::convertDouble(str);
		}
		else if (std::isdigit(str[0]))
			ConvertUtils::convertInteger(str);
		else
			ConvertUtils::convertCharacter(str);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
}