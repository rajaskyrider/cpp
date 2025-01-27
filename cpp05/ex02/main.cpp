/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:51:12 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/27 12:12:47 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat grunt(130, "low");
	Bureaucrat boss(40, "low");
	Bureaucrat president(4, "low");
	ShrubberyCreationForm sform("tree");
	RobotomyRequestForm rform("robo");
	PresidentialPardonForm pform("pardon");
	
	grunt.signForm(sform);
	grunt.executeForm(sform);
	boss.signForm(rform);
	boss.executeForm(rform);
	president.signForm(pform);
	president.executeForm(pform);
}