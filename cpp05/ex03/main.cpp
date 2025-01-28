/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:51:12 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/28 14:26:24 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void processForm(Intern& intern, Bureaucrat& boss, const std::string& formName, const std::string& target)
{
    try
    {
        AForm* form = intern.makeForm(formName, target);
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form; // Clean up dynamically allocated memory
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    Bureaucrat boss(1, "Boss");
    Intern intern;

    processForm(intern, boss, "shrubbery creation", "shrub");
    processForm(intern, boss, "robotomy request", "bot");
    processForm(intern, boss, "presidential pardon", "npc");
    processForm(intern, boss, "wrong form", "mc");
}