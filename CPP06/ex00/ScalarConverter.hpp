/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:24:25 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/17 17:24:19 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cmath>

#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define FLOAT_MAX 3.40282e+38f
#define DOUBLE_MAX 1.79769e+308

class	ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter& operator=(ScalarConverter const &rhs);
		static void PseudoHandler(std::string str);
		static void CharHandler(char c);
		static void IntHandler(int n);
		static void FloatHandler(float f);
		static void DoubleHandler(double d);

	public:
		static void	convert(std::string value);
};

enum	type 
{
	PSEUDO_LITERALS,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

#endif
