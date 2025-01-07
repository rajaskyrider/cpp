/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:44:20 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/06 15:25:23 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void	replace(std::ofstream &newfile, std::string &line, const std::string &s1, const std::string &s2)
{
	std::size_t start = 0;
	std::size_t	pos = 0;

	while ((pos = line.find(s1, start)) != std::string::npos)
	{
		newfile << line.substr(start, pos - start);
		newfile << s2;
		start = pos + s1.length();
	}
	newfile << line.substr(start);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of inputs" << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error opening the file "  << argv[1] << std::endl;
		return (1);
	}
	std::ofstream newfile((std::string(argv[1]) + ".replace").c_str());
	if (!newfile.is_open())
	{
		std::cerr << "Error creating the file " << argv[1] << ".replace" << std::endl;
		return (1);
	}
	std::string line;
	std::string s1 = argv[2];
	std::string	s2 = argv[3];
	if (s1.empty()) 
	{
    	std::cerr << "Error: s1 cannot be an empty string." << std::endl;
    	return (1);
	}
	while (std::getline(file, line))
	{
		replace(newfile, line, s1, s2);
		newfile << std::endl;
	}
	file.close();
    newfile.close();
	return (0);
}