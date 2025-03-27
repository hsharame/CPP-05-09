/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:51:43 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/27 15:55:36 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		Span sp = Span(3);
		sp.displaySpan();
		sp.addNumber(76253);
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		sp.addNumber(42);
		sp.addNumber(7);
		sp.displaySpan();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		try
		{
			sp.addNumber(8);
			sp.addNumber(9);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		Span sp = Span(15000);
		sp.displaySpan();
		for (int i = 0; i < 15000; i++)
			sp.addNumber(i % 42);
		//sp.displaySpan();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		try
		{
			sp.addNumber(42);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(78);
		sp.addNumber(9);
		sp.displaySpan();
		std::vector<int>vec;
		vec.push_back(43);
		vec.push_back(42);
		vec.push_back(7);
		vec.push_back(67);
		try
		{
			sp.addRange(vec.begin(), vec.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		sp.displaySpan();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		Span sp = Span(8);
		sp.addNumber(1);
		sp.addNumber(1);
		sp.displaySpan();
		std::deque<int>deq;
		deq.push_back(5);
		deq.push_back(2);
		deq.push_back(8);
		deq.push_back(21);
		deq.push_back(3);
		deq.push_back(34);
		deq.push_back(55);
		deq.push_back(13);
		try
		{
			sp.addRange(deq.begin(), deq.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		sp.displaySpan();
	}
	return 0;
}
