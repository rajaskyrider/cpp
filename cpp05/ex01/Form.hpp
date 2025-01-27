/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 22:58:37 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/26 20:58:24 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
# define __FORM_HPP__

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const m_name;
		bool m_sign;
		int const m_signreq;
		int	const m_execreq;
		Form();
		Form& operator=(Form& other);

	public:
		Form(Form& other);
		Form(std::string name, int reqgrade, int execgrade);
		~Form();

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
};

std::ostream& operator<<(std::ostream &stream, const Form& form);

#endif