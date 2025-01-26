/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:25:56 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/26 21:26:07 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(AForm& other): m_name(other.m_name), m_sign(other.m_sign), m_signreq(other.m_signreq), m_execreq(other.m_execreq)
{}

AForm::AForm(std::string name, int reqgrade, int execgrade): m_name(name), m_sign(false), m_signreq(reqgrade), m_execreq(execgrade)
{
	if (reqgrade > 150 || execgrade > 150)
		throw(AForm::GradeTooLowException());
	else if (reqgrade < 1 || execgrade < 1)
		throw(AForm::GradeTooHighException());
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
	return (m_name);
}

bool AForm::getStatus() const
{
	return (m_sign);
}

int	 AForm::getSignreq() const
{
	return (m_signreq);
}

int	 AForm::getExecreq() const
{
	return (m_execreq);
}

void	AForm::setStatus(bool sign)
{
	this->m_sign = sign;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->m_signreq)
		this->m_sign = true;
	else
		throw(AForm::GradeTooLowException());
}

std::ostream& operator<<(std::ostream &stream, const AForm& form)
{
	stream << form.getName() << " form is " << (form.getStatus() ? "signed" : "not signed") <<  ". The grade required to sign it is " << form.getSignreq() <<" and the grade required to execute is " << form.getExecreq() << std::endl;
	return (stream);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("Grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade too low.");
}