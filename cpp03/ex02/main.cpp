/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:50:18 by rpandipe          #+#    #+#             */
/*   Updated: 2025/01/08 14:15:54 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "==== Creating FragTrap Objects ====" << std::endl;

    FragTrap frag1("Fraggy");
    std::cout << std::endl;

    FragTrap frag2(frag1);
    std::cout << std::endl;

    FragTrap frag3("Temporary");
    frag3 = frag1;
    std::cout << std::endl;

    std::cout << "==== Testing Member Functions ====" << std::endl;

    frag1.attack("Enemy1");
    frag1.takeDamage(50);
    frag1.beRepaired(30);
    std::cout << std::endl;

    frag1.highFivesGuys();
    std::cout << std::endl;

    std::cout << "==== Testing with Multiple FragTraps ====" << std::endl;

    FragTrap frag4("Fragzilla");
    frag4.highFivesGuys();
    frag4.attack("Enemy2");
    frag4.takeDamage(100);
    frag4.beRepaired(20);
    frag4.takeDamage(100);
    std::cout << std::endl;

    std::cout << "==== Destruction Phase ====" << std::endl;

    return 0;
}