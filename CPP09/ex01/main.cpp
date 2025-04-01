/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:48:35 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/01 17:24:51 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	findOperator(int op1, int op2, char c)
{
	switch(c)
	{
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		default:
			if (op2 == 0)
			{
				std::cerr << "Error: : Divide by zero" << std::endl;
				return INT_MIN;
			}
			return op1 / op2;
	}
}

bool	isoperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*') ? true : false;
}

bool	runCalculation(RPN *myRPN)
{
	std::string value;
	std::string input = myRPN->getStr();
	size_t start = 0;
	size_t end = input.find(" ");
	while (end != std::string::npos)
	{
		end = input.find(" ", start);
		value = input.substr(start, end - start);
		if (value.size() > 1)
		{
			std::cerr << "Error" << std::endl;
			return false;
		}
		if (isdigit(value[0]))
			myRPN->getInput().push(value[0] - '0');
		else if (isoperator(value[0]) && myRPN->getInput().size() >= 2)
		{
			int operand1(0), operand2(0), res(0);
			operand2 = myRPN->getInput().top();
			myRPN->getInput().pop();
			operand1 = myRPN->getInput().top();
			myRPN->getInput().pop();
			res = findOperator(operand1, operand2, value[0]);
			if (res == INT_MIN)
				return false;
			myRPN->getInput().push(res);
		}
		else if (end != std::string::npos)
		{
			std::cerr << "Error" << std::endl;
			return false;
		}
		start += 2;
	}
	return true;
}

bool	parsInput(int argc, char *argv[], RPN *myRPN)
{
	std::string	input;
	if (argc == 2)
		input = argv[1];
	else
	{
		for(int i = 1; argv[i]; i++)
		{
			input += (argv[i]);
			if (argv[i + 1])
				input += " ";
		}
	}
	for (int i = 0; input[i]; i++)
	{
		if (!isdigit(input[i]) && input[i] != ' ' &&
			(input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/'))
			return false;
	}
	myRPN->setStr(input);
	return true;
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return ((std::cerr << "Error" << std::endl), 1);
	RPN myRPN;
	if (!parsInput(argc, argv, &myRPN))
		return ((std::cerr << "Error" << std::endl), 1);
	if (runCalculation(&myRPN))
		std::cout << myRPN.getInput().top() << std::endl;
	return 0;
}
