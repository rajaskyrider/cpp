/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:23:07 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/27 12:15:23 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), m_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other): AForm(other)
{}

RobotomyRequestForm::~RobotomyRequestForm(){}

void  RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getStatus())
	{
		if (executor.getGrade() > this->getExecreq())
			throw(AForm::GradeTooLowException());
		std::srand(time(0));
		if ((std::rand() % 100 + 1) > 50)
			std::cout << this->m_target << " has been robotomized" << std::endl;
		else
			std::cout << this->m_target << " robotomy failed" << std::endl;
	}
	else
		throw(AForm::FormNotSignedException());
}