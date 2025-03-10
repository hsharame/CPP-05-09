/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:24:22 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/10 17:54:24 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &rhs) { 
	(void) rhs;
	return *this; }

void ScalarConverter::PseudoHandler(std::string str)
{

}

void ScalarConverter::CharHandler(char c)
{

}

void ScalarConverter::IntHandler(int n)
{

}

void ScalarConverter::FloatHandler(float f)
{

}

void ScalarConverter::DoubleHandler(double d)
{
	
}

void	ScalarConverter::convert(std::string value)
{
	if (value.empty())
	{
		std::cerr << "Error: input value is empty." << std::endl;
		return ;
	}
	long int result = -1;
	double d_result = -1;
	int	type = -1;
	if (value == "-inff" || value == "+inff" || value == "nanf"
		|| value == "-inf" || value == "+inf" || value == "nan")
		type = PSEUDO_LITERALS;
	else if (value.size() == 1 && !isdigit(value[0]))
		type = CHAR;
	else
	{
		char 	*end;
		result = strtol(value.c_str(), &end, 0);
		if (*end == '\0' && (result >= INT_MIN && result <= INT_MAX))
			type = INT;
		else 
		{
			d_result = strtod(value.c_str(), &end);
			if (*end == 'f' && *(end + 1) == '\0' && (d_result >= FLOAT_MIN && d_result <= FLOAT_MAX))
				type = FLOAT;
			else if (*end == '\0' && (d_result >= DOUBLE_MIN && d_result <= DOUBLE_MAX))
				type = DOUBLE;
		}
	}
	switch(type)
	{
		case PSEUDO_LITERALS:
			ScalarConverter::PseudoHandler(value);
			break;
		case CHAR:
			ScalarConverter::CharHandler(value[0]);
			break;
		case INT:
			ScalarConverter::IntHandler(result);
			break;
		case FLOAT:
			ScalarConverter::FloatHandler(d_result);
			break;
		case DOUBLE:
			ScalarConverter::DoubleHandler(d_result);
			break;
		default :
			std::cerr << "Error: input value is unrecognized." << std::endl;
	}
}
