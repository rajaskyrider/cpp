/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:54:27 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/13 17:35:17 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	

	std::cout << "Expected output: " << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;  // ✅ Equivalent to stack's `top()`
    
    mlist.pop_back();  // ✅ Equivalent to stack's `pop()`
    std::cout << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    // ✅ Iterator traversal (Works directly in std::list)
    std::list<int>::iterator itl = mlist.begin();
    std::list<int>::iterator itle = mlist.end();
    
    ++itl;
    --itl;

    while (itl != itle)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }

	std::cout << "\n==== Different constructor Test ====" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Copied stack size: " << s.size() << " (Expected: " << mstack.size() << ")" << std::endl;
	
	MutantStack<int> assignedStack;
    assignedStack = mstack;
    std::cout << "Assigned stack size: " << assignedStack.size() << " (Expected: " << mstack.size() << ")" << std::endl;


	std::cout << "\n==== Iterator Test ====" << std::endl;
    MutantStack<int> m1stack;

    m1stack.push(5);
    m1stack.push(3);
    m1stack.push(7);
    m1stack.push(1);

    std::cout << "Iterating through MutantStack using iterators: ";
    for (MutantStack<int>::iterator it1 = m1stack.begin(); it1 != m1stack.end(); ++it1)
    {
        std::cout << *it1 << " ";
    }
    std::cout << "\n(Expected: 5 3 7 1)" << std::endl;

    return 0;
}