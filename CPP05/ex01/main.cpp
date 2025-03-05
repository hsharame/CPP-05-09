/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:14:18 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/05 13:43:53 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		try
		{
			Bureaucrat	Jane("Jane", 30);
			std::cout << Jane << std::endl;
			std::cout << "Try to creat Alice, bureaucrat grade 151..." << std::endl;
			Bureaucrat	Alice("Alice", 151);
			std::cout << Alice << std::endl;
			Bureaucrat	Bob("Bob", 0); //never executed
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;;
	{
		try
		{
			Bureaucrat Louis("Louis", 1);
			std::cout << Louis << std::endl;
			Louis.decrementGrade();
			std::cout << Louis << std::endl;
			Louis.incrementGrade();
			std::cout << Louis << std::endl;
			Louis.incrementGrade();
			std::cout << Louis << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;;
	{
		try
		{
			Bureaucrat Marc("Marc", 149);
			std::cout << Marc << std::endl;
			Marc.decrementGrade();
			std::cout << Marc << std::endl;
			Marc.decrementGrade();
			std::cout << Marc << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;;
	{
		try
		{
			Bureaucrat Alex("Alex", 42);
			std::cout << Alex << std::endl;
			Alex.incrementGrade();
			std::cout << Alex << std::endl;
			Alex.incrementGrade();
			std::cout << Alex<< std::endl;
			Alex.decrementGrade();
			std::cout << Alex<< std::endl;
			Alex.decrementGrade();
			std::cout << Alex<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;;
	{
		std::string name;
		int	grade;
		std::cout << "Enter a name of your bureaucrat : ";
		std::cin >> name;
		std::cout << "Enter a grade of your bureaucrat : ";
		std::cin >> grade;
		try
		{
			Bureaucrat your(name, grade);
			std::cout << your << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	return 0;
}
