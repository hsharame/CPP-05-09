/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:14:18 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/07 12:40:41 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		try
		{
			Bureaucrat	Alice("Alice", 67);
			Bureaucrat	Bob("Bob", 3);
			Bureaucrat	Jack("Jack", 1);
			Form		C28("C28", 5, 2);
			//Form		C27("C29", 0, 8);
			//Bureaucrat	Jane("Jane", -7);
			std::cout << Alice << std::endl;
			std::cout << Bob << std::endl;
			std::cout << Jack << std::endl;
			std::cout << C28 << std::endl;
			Bob.signForm(C28);
			Alice.signForm(C28);
			Jack.signForm(C28);
			std::cout << C28 << std::endl;
			//Form		C29("C29", 156, 8);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		try
		{
			Bureaucrat	Mike("Mike", 4);
			Form		CERFA451("CERFA451", 3, 1);
			std::cout << Mike << std::endl;
			std::cout << CERFA451 << std::endl;
			Mike.signForm(CERFA451);
			std::cout << CERFA451 << std::endl;
			Mike.incrementGrade();
			std::cout << Mike << std::endl;
			Mike.signForm(CERFA451);
			std::cout << CERFA451 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	return 0;
}
