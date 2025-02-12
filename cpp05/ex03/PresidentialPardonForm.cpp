/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:36:58 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/30 11:35:06 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), m_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{}

PresidentialPardonForm::~PresidentialPardonForm(){}

void  PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

	if (this->getStatus())
	{
		if (executor.getGrade() > this->getExecreq())
			throw(AForm::GradeTooLowException());
		std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
		throw(AForm::FormNotSignedException());
}