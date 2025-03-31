/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:48:35 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/31 18:16:35 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	runCalculate(RPN *myRPN)
{
	std::string value;
	std::string input = myRPN->getStr();
	size_t start = 0;
	size_t end = input.find(" ");
	while (end != std::string::npos)
	{
		value = input.substr(start, end);
		if (value.size() > 1)
		{
			std::cerr << "Error" << std::endl;
			return;
		}
		if (isdigit(value[0]))
			myRPN->getInput().push(static_cast<int>(value[0]));
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
	runCalculate(&myRPN);
	return 0;
}
