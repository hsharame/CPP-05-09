/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:24:22 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/14 14:16:21 by hsharame         ###   ########.fr       */
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
	std::string value_float = str;
	std::string value_double = str;
	if (value_float[value_float.size() - 1] != 'f')
		value_float = str + "f";
	else if (str == "-inf" || str == "+inf")
		value_float = str + "f";
	else
		value_double = str.substr(0, (str.size() - 1));
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << value_float << std::endl;
	std::cout << "double: " << value_double << std::endl;
}

void ScalarConverter::CharHandler(char c)
{
	if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else 
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::IntHandler(int n)
{
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (!isprint(n))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	}
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void ScalarConverter::FloatHandler(float f)
{
	if (f < 0 || f > 127)
	std::cout << "char: impossible" << std::endl;
	else
	{
		if (!isprint(static_cast<int>(f)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	}
	if (f <= static_cast<float>(INT_MIN) || f >= static_cast<float>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	double fractpart, intpart;
	fractpart = modf(f, &intpart);
	if (fractpart == 0)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

void ScalarConverter::DoubleHandler(double d)
{
	if (d < 0 || d > 127)
	std::cout << "char: impossible" << std::endl;
	else
	{
		if (!isprint(static_cast<int>(d)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	}
	if (d <= static_cast<double>(INT_MIN) || d >= static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	double fractpart, intpart;
	fractpart = modf(d, &intpart);
	if (fractpart == 0)
	{
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
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
			if ((*end == 'f' && *(end + 1) == '\0' && (d_result >= FLOAT_MIN && d_result <= FLOAT_MAX))
				|| (value == "0.0f"))
				type = FLOAT;
			else if ((*end == '\0' && (d_result >= DOUBLE_MIN && d_result <= DOUBLE_MAX))
				|| value == "0.0")
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
			ScalarConverter::IntHandler(static_cast<int>(result));
			break;
		case FLOAT:
			ScalarConverter::FloatHandler(static_cast<float>(d_result));
			break;
		case DOUBLE:
			ScalarConverter::DoubleHandler(d_result);
			break;
		default :
			std::cerr << "Error: input value is unrecognized." << std::endl;
	}
}
