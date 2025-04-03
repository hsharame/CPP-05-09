/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:19:07 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/03 11:06:13 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string parsDate(std::string date)
{
	std::string res = date;
	int year, month, day;
	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		res.insert(0, "Error: bad input => ");
	else if ((year < 2009 || year > 3000) || (month < 1 || month > 12) || (day < 1 || day > 31))
		res.insert(0, "Error: bad input => ");
	return res;
}

void multiplyByRate(float value, std::string date, std::map<std::string, float> const &bd)
{
	std::cout << date << "=> " << value << " = ";
	std::map<std::string, float>::const_iterator rate = bd.lower_bound(date);
	--rate;
	float res = rate->second * value;
	std::cout << res << std::endl;
}

std::map<std::string, float> loadData(std::string filename, std::string delimit)
{
	std::map<std::string, float> res;
	std::ifstream ifs(filename.c_str());
	if (!ifs)
	{
		std::cerr << "Can't open data base file" << std::endl;
		return res;
	}
	std::string	line, date, value;
	std::getline(ifs, line);
	while(std::getline(ifs, line))
	{
		size_t pos = line.find_first_of(delimit);
		if (pos != std::string::npos)
		{
			date = parsDate(line.substr(0, pos));
			value = line.substr(pos+1);
			if (!value.empty())
			{
				float floValue = std::strtof(value.c_str(), 0);
				if (floValue < 0)
					date = "Error: not a positive number.";
				if (floValue > 1000)
					date = "Error: too large a number.";
				res[date] = floValue;
			}
		}
    }
	return res;
}

void	runExchange(std::string filename, std::map<std::string, float> const &bd)
{
	std::map<std::string, float> res;
	std::ifstream ifs(filename.c_str());
	if (!ifs)
	{
		std::cerr << "Can't open input file" << std::endl;
		return ;
	}
	std::string	line, date, value;
	std::getline(ifs, line);
	while(std::getline(ifs, line))
	{
		size_t pos = line.find_last_of("|");
		if (pos != std::string::npos)
		{
			date = parsDate(line.substr(0, pos));
			if (date.size() > 5 && date.find("Error") != std::string::npos)
			{
				std::cerr << date << std::endl;
				continue ;
			}
			value = line.substr(pos+1);
			if (value.empty())
				continue ;
			float floValue = std::strtof(value.c_str(), 0);
			if (floValue < 0)
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}
			if (floValue > 1000)
			{
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}
			multiplyByRate(floValue, date, bd);
		}
		else if (line.size() > 9)
		{
			date = parsDate(line.substr(0, 10));
			if (date.size() > 5 && date.find("Error") != std::string::npos)
				std::cerr << date << std::endl;
			else
				std::cerr << "Error: bad line format => " << line << std::endl;
		}
	}
	return ;
}


int	main(int argc, char* argv[])
{
	if (argc != 2)
		return ((std::cerr << "Error: could not open file." << std::endl), 1);
	BitcoinExchange	btc;
	btc.setBd(loadData("data.csv", ","));
	const std::map<std::string, float> &bdRef = btc.getBd();
	runExchange(argv[1], bdRef);
	return 0;
}
