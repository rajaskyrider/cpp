/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:25:54 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/27 10:52:50 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(Form& other): m_name(other.m_name), m_sign(other.m_sign), m_signreq(other.m_signreq), m_execreq(other.m_execreq)
{}

Form::Form(std::string name, int reqgrade, int execgrade): m_name(name), m_sign(false), m_signreq(reqgrade), m_execreq(execgrade)
{
	if (reqgrade > 150 || execgrade > 150)
		throw(Form::GradeTooLowException());
	else if (reqgrade < 1 || execgrade < 1)
		throw(Form::GradeTooHighException());
}

Form& Form::operator=(Form& other)
{
	this->m_sign = other.getStatus();
}

Form::~Form()
{}

std::string Form::getName() const
{
	return (m_name);
}

bool Form::getStatus() const
{
	return (m_sign);
}

int	 Form::getSignreq() const
{
	return (m_signreq);
}

int	 Form::getExecreq() const
{
	return (m_execreq);
}

void	Form::setStatus(bool sign)
{
	this->m_sign = sign;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->m_signreq)
		this->m_sign = true;
	else
		throw(Form::GradeTooLowException());
}

std::ostream& operator<<(std::ostream &stream, const Form& form)
{
	stream << form.getName() << " form is " << (form.getStatus() ? "signed" : "not signed") <<  ". The grade required to sign it is " << form.getSignreq() <<" and the grade required to execute is " << form.getExecreq() << std::endl;
	return (stream);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade too low.");
}