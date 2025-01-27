/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:32:58 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/26 21:01:37 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(int grade, std::string name): m_name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): m_name(other.getName())
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->m_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return (this->m_name);
}

int Bureaucrat::getGrade() const
{
	return (this->m_grade);
}

void	Bureaucrat::upGrade()
{
	if (this->m_grade > 1)
		this->m_grade--;
	else
		throw(Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::downGrade()
{
	if (this->m_grade < 150)
		this->m_grade++;
	else
		throw(Bureaucrat::GradeTooLowException());
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("A bureaucrat can't have a grade greater than 1.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("A bureaucrat can't have a grade lower than 150.");
}

void Bureaucrat::signForm(Form& form) 
{
    try 
	{
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    } 
	catch (const std::exception& e) 
	{
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return stream;
}
