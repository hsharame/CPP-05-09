/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:51:48 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/27 17:03:33 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <deque>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(Span const &src);
		Span& operator=(Span const &rhs);

		void addNumber(int number);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
		template <typename T>
			void addRange(T begin, T end)
			{
				while (begin != end)
				{
					if (this->_i == this->_N)
						throw FullStorage();
					this->_stock.push_back(*begin);
					this->_i++;
					++begin;
				}
			}
		
			void displaySpan() const;

		class FullStorage : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NoDistanceCanBeFound: public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		std::vector<int> _stock;
		unsigned int	_i;
		unsigned int	_N;
};

#endif
