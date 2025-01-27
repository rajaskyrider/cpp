/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:22:43 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/27 11:39:30 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		std::string const m_name;
		int			m_grade;
		Bureaucrat(void);
		
	public:
		Bureaucrat(int grade, std::string name);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		std::string getName () const;
		int getGrade () const;
		void	upGrade();
		void	downGrade();
		void	signForm(AForm& form);
		void	executeForm(AForm const & form);
		class	GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

#endif