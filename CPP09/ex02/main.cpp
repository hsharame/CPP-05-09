/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:49:26 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/02 17:56:38 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	parsInput(int argc, char *argv[], PmergeMe *myPmerge)
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
		if (!isdigit(input[i]) && !isspace(input[i]))
			return false;
	}
	return true;
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return ((std::cerr << "Error: No arguments" << std::endl), 1);
	PmergeMe myPmerge;
	if (!parsInput(argc, argv, &myPmerge))
		return ((std::cerr << "Error" << std::endl), 1);
	return 0;
}
