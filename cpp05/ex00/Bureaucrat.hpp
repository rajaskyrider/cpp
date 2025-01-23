/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:22:43 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/23 22:57:15 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Bureaucrat
{
	private:
		std::string const m_name;
		int			m_grade;
		Bureaucrat(void);
		void checkgrade();
	public:
		Bureaucrat(int grade, std::string name);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		std::string getName () const;
		int getGrade () const;
		void	upGrade();
		void	downGrade();
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