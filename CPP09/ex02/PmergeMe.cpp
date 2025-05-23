/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:49:22 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/04 18:43:46 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _error(false) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) 
{
	*this = src;
}

PmergeMe& PmergeMe::operator=(PmergeMe const &rhs){
	if (this != &rhs)
	{
		this->_inputV = rhs._inputV;
		this->_inputD = rhs._inputD;
		this->_sortedV = rhs._sortedV;
		this->_sortedD = rhs._sortedD;
		this->_error = rhs._error;
	}
	return *this;
}

void	PmergeMe::setInputV(std::vector<int> toSet) { this->_inputV = toSet;}
std::vector<int>& PmergeMe::getInputV() { return this->_inputV; }
void	PmergeMe::setInputD(std::deque<int> toSet) { this->_inputD = toSet; }
std::deque<int>& PmergeMe::getInputD() { return this->_inputD; }

void	PmergeMe::setSortedV(std::vector<int> toSet) { this->_sortedV = toSet; }
std::vector<int>& PmergeMe::getSortedV() { return this->_sortedV; }
void	PmergeMe::setSortedD(std::deque<int> toSet) { this->_sortedD = toSet; }
std::deque<int>& PmergeMe::getSortedD() { return this->_sortedD; }

void	PmergeMe::setError(bool v) { this->_error = v; }
bool&	PmergeMe::getError() { return this->_error; }

double	PmergeMe::getTimeV() const { return this->_timeV; }
double	PmergeMe::getTimeD() const { return this->_timeD; }

void	PmergeMe::sortVector(std::vector<int> &v)
{
	if (v.size() < 2)
		return ;
	clock_t start = clock();
	std::vector<int> base, pending;
	for(size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] > v[i + 1])
			std::swap(v[i], v[i + 1]);
		base.push_back(v[i+1]);
		pending.push_back(v[i]);
	}
	if (v.size() % 2 != 0)
		base.push_back(v.back());
	sortVector(base);
	for (size_t i = 0; i < pending.size(); i++)
	{
		int el = pending[i];
		std::vector<int>::iterator it = std::lower_bound(base.begin(), base.end(), el);
		base.insert(it, el);
	}
	v = base;
	clock_t end = clock();
	this->_timeV = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000;
	this->_sortedV = base;
}

void	PmergeMe::sortDeque(std::deque<int> &d)
{
	if (d.size() < 2)
		return ;
	clock_t start = clock();
	std::deque<int> base, pending;
	for(size_t i = 0; i + 1 < d.size(); i += 2)
	{
		if (d[i] > d[i + 1])
			std::swap(d[i], d[i + 1]);
		base.push_back(d[i+1]);
		pending.push_back(d[i]);
	}
	if (d.size() % 2 != 0)
		base.push_back(d.back());
	sortDeque(base);
	for (size_t i = 0; i < pending.size(); i++)
	{
		int el = pending[i];
		std::deque<int>::iterator it = std::lower_bound(base.begin(), base.end(), el);
		base.insert(it, el);
	}
	d = base;
	clock_t end = clock();
	this->_timeD = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000;
	this->_sortedD = base;
}
