/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:18:32 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/30 11:34:45 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		AForm* createShrubbery(const std::string target);
		AForm* createRobotomy(const std::string target);
		AForm* createPardon(const std::string target);
		
	public:
		Intern();
		~Intern();
		AForm* makeForm(const std::string name, const std::string target);
		class FormNotFoundException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};
#endif