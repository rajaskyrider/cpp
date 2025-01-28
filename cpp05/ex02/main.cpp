/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:51:12 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/28 10:53:47 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat grunt(130, "low");
	Bureaucrat boss(40, "low");
	Bureaucrat president(4, "low");
	ShrubberyCreationForm sform("tree");
	RobotomyRequestForm rform("robo");
	PresidentialPardonForm pform("pardon");
	
	//Test Case 0: All works
	try 
	{
		grunt.signForm(sform);
		grunt.executeForm(sform);
	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try 
	{
		boss.signForm(rform);
		boss.executeForm(rform);
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try 
	{
		president.signForm(pform);
		president.executeForm(pform);
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	// Test Case 1: Bureaucrat's grade too low to sign the form
    try
    {
        Bureaucrat lowGrade(150, "Low Grader");
        ShrubberyCreationForm sform("tree");
        lowGrade.signForm(sform); // Should throw GradeTooLowException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test 1: " << e.what() << std::endl;
    }

    // Test Case 2: Bureaucrat's grade too low to execute the form
    try
    {
        Bureaucrat lowGrade(150, "Low Grader");
        ShrubberyCreationForm sform("tree");
        lowGrade.signForm(sform);
        lowGrade.executeForm(sform); // Should throw GradeTooLowException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test 2: " << e.what() << std::endl;
    }

    // Test Case 3: Form not signed before execution
    try
    {
        Bureaucrat boss(1, "Boss");
        RobotomyRequestForm rform("robot");
        boss.executeForm(rform); // Should throw FormNotSignedException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test 3: " << e.what() << std::endl;
    }

    // Test Case 4A: Invalid Bureaucrat grade (too high)
    try
    {
        Bureaucrat invalid(0, "Invalid Grader"); // Invalid grade (too high)
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test 4A: " << e.what() << std::endl;
    }

    // Test Case 4B: Invalid Bureaucrat grade (too low)
    try
    {
        Bureaucrat invalid(200, "Invalid Grader"); // Invalid grade (too low)
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test 4B: " << e.what() << std::endl;
    }

    // Test Case 6: Form cannot be signed twice
    try
    {
        Bureaucrat boss(1, "Boss");
        PresidentialPardonForm pform("target");

        boss.signForm(pform); // First attempt (successful)
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test 6: " << e.what() << std::endl;
    }

    // Test Case 7: RobotomyRequestForm execution randomness
    try
    {
        Bureaucrat boss(1, "Boss");
        RobotomyRequestForm rform("target");

        boss.signForm(rform);
        for (int i = 0; i < 5; ++i)
        {
            boss.executeForm(rform); // 50% chance of failure
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test 7: " << e.what() << std::endl;
    }

    // Test Case 8: File creation fails in ShrubberyCreationForm
    try
    {
        Bureaucrat boss(1, "Boss");
        ShrubberyCreationForm sform("/restricted_directory/tree");

        boss.signForm(sform);
        boss.executeForm(sform); // Should print "Failed to create the file."
    }
    catch (const std::exception &e)
    {
        std::cerr << "Test 8: " << e.what() << std::endl;
    }


}