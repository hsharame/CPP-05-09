/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:49:26 by hsharame          #+#    #+#             */
/*   Updated: 2025/04/03 15:50:15 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	g_count = 0;

void extractNumbers(std::string &str, PmergeMe *myPmerge)
{
	std::stringstream ss(str);
	std::string token;
	while (ss >> token)
	{
		for (size_t i = 0; i < token.size(); i++)
		{
			if (!isdigit(token[i]))
			{
				myPmerge->setError(true);
				return;
			}
		}
		unsigned int n;
		std::istringstream(token) >> n;
		if (n > 2147483647)
		{
			myPmerge->setError(true);
			return ;
		}
		g_count++;
		myPmerge->getInputV().push_back(n);
		myPmerge->getInputD().push_back(n);
	}
}

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
	extractNumbers(input, myPmerge);
	if (myPmerge->getInputV().empty() || myPmerge->getInputD().empty() || myPmerge->getError() == true)
		return false;
	return true;
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return ((std::cerr << "Error: No arguments" << std::endl), 1);
	PmergeMe myPmerge;
	if (!parsInput(argc, argv, &myPmerge))
		return ((std::cerr << "Error" << std::endl), 1);
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = myPmerge.getInputV().begin(); it != myPmerge.getInputV().end(); it++)
		std::cout << *it << " ";
	myPmerge.sortVector(myPmerge.getInputV());
	std::cout << std::endl << "After: ";
	for (std::vector<int>::iterator it1 = myPmerge.getSortedV().begin(); it1 != myPmerge.getSortedV().end(); it1++)
		std::cout << *it1 << " ";
	std::cout << std::endl << "Time to process a range of " << g_count << " elements with std::vector : " 
	<< myPmerge.getTimeV() << " ms" << std::endl;
	std::cout << "Time to process a range of " << g_count << " elements with std::deque : " 
	<< myPmerge.getTimeD() << " ms" << std::endl;
	return 0;
}
