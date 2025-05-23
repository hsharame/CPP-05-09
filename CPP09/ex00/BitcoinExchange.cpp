/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:19:12 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/31 13:58:20 by hsharame         ###   ########.fr       */
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
		this->_bd = rhs._bd;
	return *this;
}

void	BitcoinExchange::setBd(std::map<std::string,float> toSet)
{
	this->_bd = toSet;
}

std::map<std::string, float> BitcoinExchange::getBd() const
{
	return this->_bd;
}
