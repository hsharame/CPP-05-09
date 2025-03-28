/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:19:10 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/28 18:19:46 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstring>
#include <cstddef>
#include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange& operator=(BitcoinExchange const &rhs);

		void	setBd(std::map<std::string,float> toSet);
		void	setInput(std::map<std::string,float> toSet);
		std::map<std::string, float> getBd();
		std::map<std::string, float> getInput();

	private:
		std::map<std::string, float> _bd;
		std::map<std::string, float> _input;
};

#endif
