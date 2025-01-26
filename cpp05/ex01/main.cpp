/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:46:51 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/26 21:00:44 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    try {
        // Test Case 1: Valid Bureaucrat signing a Form
        Bureaucrat bob(1, "Bob");
        Form formA("FormA", 5, 10);
        std::cout << formA << std::endl;
        bob.signForm(formA);
        std::cout << formA << std::endl;

        // Test Case 2: Bureaucrat with insufficient grade signing a Form
        Bureaucrat alice(6, "Alice");
        Form formB("FormB", 5, 10);
        std::cout << formB << std::endl;
        alice.signForm(formB);
        std::cout << formB << std::endl;

        // Test Case 3: Bureaucrat upgrading and signing a Form
        alice.upGrade();
        alice.signForm(formB);
        std::cout << formB << std::endl;

        // Test Case 4: Creating a Form with invalid grades
        try {
            Form formC("FormC", 0, 10); // Invalid grade
        } catch (const std::exception &e) {
            std::cerr << "Failed to create form: " << e.what() << std::endl;
        }

        try {
            Form formD("FormD", 151, 10); // Invalid grade
        } catch (const std::exception &e) {
            std::cerr << "Failed to create form: " << e.what() << std::endl;
        }

        // Test Case 5: Bureaucrat with maximum grade attempting to downgrade
        Bureaucrat* tom = NULL;
		try {
			tom = new Bureaucrat(150, "Tom");
			tom->downGrade(); 
		} catch (const std::exception &e) {
			if (tom) {
				std::cerr << tom->getName() << ": " << e.what() << std::endl;
			} else {
				std::cerr << "Error creating Bureaucrat: " << e.what() << std::endl;
			}
		}
		delete tom;
    } 
	catch (const std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
    }

    return 0;
}