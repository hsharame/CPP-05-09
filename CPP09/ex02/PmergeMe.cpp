/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:49:22 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/02 18:08:37 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) 
{
	*this = src;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &rhs){
	if (this != &rhs)
	{
		this->_input = rhs._input;
		this->_sorted = rhs._sorted;
	}
	return *this;
}

void	PmergeMe::setInput(std::vector<int> toSet)
{
	this->_input = toSet;
}

std::vector<int>& PmergeMe::getInput()
{
	return this->_input;
}

void	PmergeMe::setSorted(std::deque<int> toSet) 
{
	this->_sorted = toSet;
}

std::deque<int> PmergeMe::getSorted() const
{
	return this->_sorted;
}
