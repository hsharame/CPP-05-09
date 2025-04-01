/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:48:39 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/01 14:02:51 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const &src) 
{
	*this = src;
}

RPN& RPN::operator=(RPN const &rhs){
	if (this != &rhs)
		this->_input = rhs._input;
	return *this;
}

void	RPN::setInput(std::stack<int> toSet)
{
	this->_input = toSet;
}

std::stack<int>& RPN::getInput()
{
	return this->_input;
}

void	RPN::setStr(std::string toSet) 
{
	this->_str = toSet;
}

std::string RPN::getStr() const
{
	return this->_str;
}
