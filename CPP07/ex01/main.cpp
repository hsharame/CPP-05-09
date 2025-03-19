/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:13:48 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/19 12:46:18 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Cat.hpp"

int	main(void)
{
	{
		int	array[] = {1, 2, 42, 56};
		unsigned int size_array = sizeof(array) / sizeof(array[0]);
		iter(array, size_array, display<int>);
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		int	array[] = {1, 2, 42, 56};
		unsigned int size_array = sizeof(array) / sizeof(array[0]);
		iter(array, size_array, display_espace<int>);
	}
	std::cout << std::endl << std::string(50, '_') << std::endl << std::endl;
	{
		std::string array[] =
		{"hello", "world", "!", "lorem", "ipsum", "dolor", "sit", "amet"};
		unsigned int size_array = sizeof(array) / sizeof(array[0]);
		::iter(array, size_array, display);
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		std::string array[] =
		{"hello", "world", "!", "lorem", "ipsum", "dolor", "sit", "amet"};
		unsigned int size_array = sizeof(array) / sizeof(array[0]);
		::iter(array, size_array, display_espace);
	}
	std::cout << std::endl << std::string(50, '_') << std::endl << std::endl;
	{
		Cat array[5] =
		{Cat("Georges"), Cat("Felix"), Cat("Cookie"), Cat("Kochka"), Cat("Minou")};
		unsigned int size_array = sizeof(array) / sizeof(array[0]);
		iter(array, size_array, display);
	}
}
