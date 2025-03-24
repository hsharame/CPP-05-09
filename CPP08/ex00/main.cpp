/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:52:48 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/24 18:06:08 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

typedef std::list<int> IntList;

void	print(IntList &l)
{
	IntList::iterator i = l.begin();
	while (i != l.end())
	{
		std::cout << *i << " ";
		++i;
	}
	std::cout << std::endl;
}

int		main()
{
	{
		IntList	l;
		l.push_back(42);
		l.push_back(21);
		l.push_back(7);
		l.push_back(98);
		l.push_back(42);
		print(l);
		l.reverse();
		print(l);
		l.sort();
		print(l);
		try
		{
			IntList::iterator it = easyfind(l, 42);
			std::cout << *it << std::endl;
			IntList::iterator it1 = easyfind(l, 7);
			std::cout << *it1 << std::endl;
			IntList::iterator it2 = easyfind(l, 3);
			std::cout << *it2 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		typedef std::vector<int> vec;
		vec v(10);
		for (unsigned int i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		try
		{
			v.at(5) = 42;
			v.push_back(7);
			v.at(23) = 21;
		}
		catch(const std::out_of_range& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << "Vector after :" << std::endl;
		for (unsigned int i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		try
		{
			vec::iterator it1 = easyfind(v, 7);
			std::cout << *it1 << std::endl;
			vec::iterator it = easyfind(v, 3);
			std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		std::vector<int> num;
		num.push_back(3);
		num.push_back(234);
		num.push_back(7);
		num.push_back(432);
		num.push_back(9);
		const std::vector<int> numbers = num;
		try
		{
			std::vector<int>::const_iterator it = easyfind(numbers, 234);
			std::cout << *it << std::endl;
			std::vector<int>::const_iterator it1 = easyfind(numbers, 5);
			std::cout << *it1 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		std::deque<int> deq;
		deq.push_back(42);
		deq.push_back(42);
		deq.push_back(21);
		deq.push_front(21);
		for (unsigned int i = 0; i < deq.size(); i++)
			std::cout << deq[i] << " ";
		std::cout << std::endl;
		std::deque<int>::iterator it = easyfind(deq, 42);
		deq.insert(it, 7);
		for (unsigned int i = 0; i < deq.size(); i++)
			std::cout << deq[i] << " ";
		std::cout << std::endl;
		deq.erase(easyfind(deq, 42));
		for (unsigned int i = 0; i < deq.size(); i++)
			std::cout << deq[i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		std::stack<int> sta;
		if (sta.empty())
			std::cout << "Stack is empty" << std::endl;
		sta.push(1);
		sta.push(1);
		sta.push(2);
		sta.push(3);
		sta.push(5);
		sta.push(8);
		sta.push(13);
		for (unsigned int i = 0; i < sta.size(); i++)
			std::cout << sta[i] << " ";
		std::cout << std::endl;
		sta.pop();
		sta.pop();
		for (unsigned int i = 0; i < sta.size(); i++)
			std::cout << sta[i] << " ";
		std::cout << std::endl;
		/*try
		{
			std::stack<int>::iterator it = easyfind(sta, 234);
			std::cout << *it << std::endl;
			std::stack<int>::iterator it1 = easyfind(sta, 5);
			std::cout << *it1 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}*/
	}
}
