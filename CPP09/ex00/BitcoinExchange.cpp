/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:19:12 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/28 18:20:11 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) 
{
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &rhs){
	if (this != &rhs)
		static_cast<void>(rhs);
	return *this;
}

void	BitcoinExchange::setBd(std::map<std::string,float> toSet)
{
	this->_bd = toSet;
}

void	BitcoinExchange::setInput(std::map<std::string,float> toSet)
{
	this->_input = toSet;
}

std::map<std::string, float> BitcoinExchange::getBd()
{
	return this->_bd;
}

std::map<std::string, float> BitcoinExchange::getInput()
{
	return this->_input;
}
