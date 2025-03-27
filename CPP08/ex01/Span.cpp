/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:51:45 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/27 15:50:54 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _i(0), _N(0) {}

Span::Span(unsigned int N) : _i(0), _N(N) {}

Span::~Span() {}

Span::Span(Span const &src)
{
	*this = src;
}

Span& Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_i = rhs._i;
		this->_stock = rhs._stock;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (this->_i == this->_N)
		throw FullStorage();
	this->_stock.push_back(number);
	this->_i++;
}

unsigned int Span::shortestSpan()
{
	if (this->_i <= 1)
		throw NoDistanceCanBeFound();
	std::vector<int> sortedStock = this->_stock;
	std::sort(sortedStock.begin(), sortedStock.end());
	unsigned int result = std::numeric_limits<unsigned int>::max();
	for(unsigned int i = 1; i < sortedStock.size(); i++)
	{
		int diff = sortedStock[i] - sortedStock[i - 1];
		if (static_cast<unsigned int>(diff) < result)
			result = diff;
	}
	return result;
}

unsigned int Span::longestSpan()
{
	if (this->_i <= 1)
		throw NoDistanceCanBeFound();
	std::vector<int> sortedStock = this->_stock;
	std::sort(sortedStock.begin(), sortedStock.end());
	unsigned int result = 1;
	result = sortedStock.back() - sortedStock.front();
	return result;
}

void	Span::displaySpan() const
{
	std::cout << "\033[1;32mSpan Status: N: " << this->_N << "; Already contains: " << this->_i << "; Storage: " << std::endl;
	if (this->_i == 0)
	{
		std::cout << "\033[1;34mempty\033[0m" << std::endl;
		return;
	}
	for (unsigned int i = 0; i < this->_stock.size(); i++)
		std::cout << this->_stock[i] << " ";
	std::cout << std::endl << "Sorted storage :" << std::endl;
	std::vector<int> sortedStock = this->_stock;
	std::sort(sortedStock.begin(), sortedStock.end());
	for (unsigned int i = 0; i < sortedStock.size(); i++)
		std::cout << sortedStock[i] << " ";
	std::cout << "\033[0m" << std::endl;
}

const char*	Span::FullStorage::what() const throw()
{
	return "The storage is full!";
}

const char* Span::NoDistanceCanBeFound::what() const throw()
{
	return "No distance can be found!";
}
