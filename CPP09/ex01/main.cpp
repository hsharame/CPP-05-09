/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:48:35 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/02 18:05:21 by hsharame         ###   ########.fr       */
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
	std::string input = myRPN->getStr();
	for (int i = 0; input[i]; i++)
	{
		if (isspace(input[i]))
			continue ;
		if (isdigit(input[i]))
		{
			if (!input[i+1] || (input[i+1] && !isdigit(input[i+1])))
				myRPN->getInput().push(input[i] - '0');
			else if (input[i+1] && isdigit(input[i+1]))
			{
				std::cerr << "Error" << std::endl;
				return false;
			}
		}
		if (isoperator(input[i]))
		{
			if (input[i+1] && isdigit(input[i+1]) && 
				(input[i+2] && !isdigit(input[i+2])))
			{
				if (input[i] == '-')
					myRPN->getInput().push((input[++i] - '0') * -1);
				else if (input[i] == '+')
					myRPN->getInput().push(input[++i] - '0');
				else
				{
					std::cerr << "Error" << std::endl;
					return false;
				}
			}
			else if (myRPN->getInput().size() >= 2)
			{
				int operand1(0), operand2(0), res(0);
				operand2 = myRPN->getInput().top();
				myRPN->getInput().pop();
				operand1 = myRPN->getInput().top();
				myRPN->getInput().pop();
				res = findOperator(operand1, operand2, input[i]);
				if (res == INT_MIN)
					return false;
				myRPN->getInput().push(res);
			}
		}
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
		if (!isdigit(input[i]) && !isspace(input[i]) &&
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
