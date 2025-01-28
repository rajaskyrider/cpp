/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:58:37 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/27 12:08:12 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		std::string const m_name;
		bool m_sign;
		int const m_signreq;
		int	const m_execreq;
		AForm();

	public:
		AForm(AForm& other);
		AForm(std::string name, int reqgrade, int execgrade);
		AForm& operator=(AForm& other);
		virtual ~AForm();

		std::string getName() const;
		bool getStatus() const;
		int	 getSignreq() const;
		int	 getExecreq() const;
		void	setStatus(bool sign);
		void	beSigned(const Bureaucrat& bureaucrat);

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
		class	FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &stream, const AForm& form);

#endif