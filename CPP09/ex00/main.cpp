/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:19:07 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/28 18:25:32 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string parsDate(std::string date)
{
	std::string res = date;
	int year, month, day;
	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		res.insert(0, "Error: bad input => ");
	if ((year < 2009 || year > 3000) || (month < 1 || month > 12) || (day < 1 || day > 31))
		res.insert(0, "Error: bad input => ");
	return res;
}

std::map<std::string, float> loadData(std::string filename, std::string delimit)
{
	std::map<std::string, float> res;
	std::ifstream ifs(filename.c_str(), std::ios::binary);
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

int	main(int argc, char* argv[])
{
	if (argc != 2)
		return ((std::cerr << "Error: could not open file." << std::endl), 1);
	BitcoinExchange	btc;
	//btc.setBd(loadData("data.csv", ","));
	btc.setInput(loadData(argv[1], "|"));
	std::map<std::string, float> bd = btc.getInput();
	std::map<std::string, float>::iterator it = bd.begin();
	std::map<std::string, float>::iterator ite = bd.end();
	while (it != ite)
	{
		std::cout << it->first << " " << it->second << std::endl;
		++it;
	}
}

//penser comment faire en sorte pour que dasn iput si jamais il y a la memem date ca ne reecrit pas la case
