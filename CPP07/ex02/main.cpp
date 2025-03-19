/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:38:18 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/19 14:45:49 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	//subject tests
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	//my tests
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		Array<int> vide(10);
		for (unsigned int i = 0; i < vide.size(); i++)
			std::cout << vide[i] << " ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < vide.size(); i++)
			vide[i] = i + 1;
		for (unsigned int i = 0; i < vide.size(); i++)
			std::cout << vide[i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		Array<int> caractere(10);
		char	c = '*';
		for (unsigned int i = 0; i < caractere.size(); i++)
			std::cout << caractere[i] << " ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < caractere.size(); i++)
			caractere[i] = c++;
		for (unsigned int i = 0; i < caractere.size(); i++)
			std::cout << caractere[i] << " ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < caractere.size(); i++)
			std::cout << static_cast<char>(caractere[i]) << " ";
		std::cout << std::endl;
		try
		{
			std::cout << caractere[1] << std::endl;
			std::cout << caractere[11] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		int n = 42;
		Array<int> nb(3);
		for (unsigned int i = 0; i < nb.size(); i++)
			std::cout << nb[i] << " ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < nb.size(); i++)
			nb[i] = n;
		Array <int> copie = nb;
		std::cout << "orignal: ";
		for (unsigned int i = 0; i < nb.size(); i++)
			std::cout << nb[i] << " ";
		std::cout << std::endl << "copy: ";
		for (unsigned int i = 0; i < copie.size(); i++)
			std::cout << copie[i] << " ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < nb.size(); i++)
			nb[i] = 24;
		std::cout << "orignal: ";
		for (unsigned int i = 0; i < nb.size(); i++)
			std::cout << nb[i] << " ";
		std::cout << std::endl << "copy: ";
		for (unsigned int i = 0; i < copie.size(); i++)
			std::cout << copie[i] << " ";
		std::cout << std::endl;
		for (unsigned int i = 0; i < copie.size(); i++)
			copie[i] = 7;
		std::cout << "orignal: ";
		for (unsigned int i = 0; i < nb.size(); i++)
			std::cout << nb[i] << " ";
		std::cout << std::endl << "copy: ";
		for (unsigned int i = 0; i < copie.size(); i++)
			std::cout << copie[i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		const Array<int> nb(3);
		try
		{
			std::cout << nb[1] << std::endl;
			std::cout << nb[3] << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
    return 0;
}
