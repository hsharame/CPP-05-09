/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:58:46 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/27 17:22:07 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list> 

int main()
{
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
		std::stack<int> s(mstack);
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("hello");
		mstack.push("world");
		std::cout << "MutantStack: " << std::endl;
		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<std::string> mstack1(mstack);
		std::cout << "La taille de la copie de MutantStack: " <<  mstack1.size() << std::endl;
		mstack.push("lorem");
		mstack.push("ipsem");
		std::cout << "MutantStack: " << std::endl;
		mstack.pop();
		MutantStack<std::string>::iterator it1 = mstack.begin();
		MutantStack<std::string>::iterator ite1 = mstack.end();
		while (it1 != ite1)
		{
			std::cout << *it1 << std::endl;
			++it1;
		}
		std::cout << "MutantStack a l'envers: " << std::endl;
		MutantStack<std::string>::reverse_iterator it2 = mstack.rbegin();
		MutantStack<std::string>::reverse_iterator ite2 = mstack.rend();
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
	}
	return 0;
}
