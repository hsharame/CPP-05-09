/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:48:41 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/01 13:36:05 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(RPN const &src);
		RPN& operator=(RPN const &rhs);

		void	setInput(std::stack<int> toSet);
		std::stack<int> getInput() const;
		void	setStr(std::string toSet);
		std::string getStr() const;

	private:
		std::stack<int> _input;
		std::string	_str;
};

#endif
