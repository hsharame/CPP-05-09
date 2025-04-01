/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:48:35 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/01 13:51:58 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	findOperator(int op1, int op2, char c)
{
	int res(0);
	switch(c)
	{
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			if (op2 == 0)
			{
				std::cerr << "Error: : Divide by zero" << std::endl;
				exit(1);
			}
			return op1 / op2;
		default:
			return res;
	}
}

bool	isoperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*') ? true : false;
}

void	runCalculation(RPN *myRPN)
{
	std::string value;
	std::string input = myRPN->getStr();
	size_t start = 0;
	size_t end = input.find(" ");
	while (end != std::string::npos)
	{
		std::cout << "boucle" << std::endl;
		value = input.substr(start, end - start);
		if (value.size() > 1)
		{
			std::cerr << "Error df" << std::endl;
			return;
		}
		std::cout << "value: " << value << std::endl;
		if (isdigit(value[0]))
			myRPN->getInput().push(static_cast<int>(value[0]));
		else if (isoperator(value[0]) && myRPN->getInput().size() == 2)
		{
			int operand1(0), operand2(0), res(0);
			operand1 = myRPN->getInput().top();
			std::cout << operand1 << std::endl;
			myRPN->getInput().pop();
			operand2 = myRPN->getInput().top();
			std::cout << operand1 << std::endl;
			myRPN->getInput().pop();
			res = findOperator(operand1, operand2, value[0]);
			myRPN->getInput().push(res);
		}
		else
		{
			std::cout << value[0] << " " << myRPN->getInput().size() << std::endl;
			std::cerr << "Error d" << std::endl;
			return;
		}
		int operand3;
		operand3 = myRPN->getInput().top();
		std::cout << operand3 << std::endl;
		start += 2;
		end = input.find(" ", start);
	}
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
			input.append(argv[i]);
			input.append(" ");
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
	runCalculation(&myRPN);
	return 0;
}
