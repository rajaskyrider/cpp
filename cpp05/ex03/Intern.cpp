/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:22:09 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/28 13:53:59 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern(){}

Intern::~Intern(){}

AForm* Intern::createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPardon(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Requested form not found.");
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	AForm* (Intern::*funcptr[3]) (const std::string) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPardon};
	std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for(int i = 0; i < 3; i++)
	{
		if (form_names[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*funcptr[i])(target));
		}
	}
	throw(Intern::FormNotFoundException());
}