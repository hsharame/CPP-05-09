/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:14:18 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/07 13:47:49 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		Bureaucrat Alice("Alice", 32);
		ShrubberyCreationForm form("home");
		Alice.signForm(form);
		Alice.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	try
	{
		Bureaucrat Bob("Bob", 145);
		ShrubberyCreationForm form("home");
		Bob.signForm(form);
		Bob.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	try
	{
		Bureaucrat Mike("Mike", 32);
		Bureaucrat Leo("Leo", 76);
		ShrubberyCreationForm form("home");
		ShrubberyCreationForm form1("Arbre");
		Mike.executeForm(form);
		Mike.signForm(form1);
		Leo.executeForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	try
	{
		Bureaucrat Mike("Mike", 32);
		Bureaucrat Bob("Bob", 145);
		Bureaucrat Alice("Alice", 3);
		RobotomyRequestForm form("home");
		Mike.signForm(form);
		Bob.signForm(form);
		Alice.signForm(form);
		Mike.executeForm(form);
		Bob.executeForm(form);
		Alice.executeForm(form);
		Mike.executeForm(form);
		Mike.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	try
	{
		Bureaucrat Mike("Mike", 25);
		Bureaucrat Bob("Bob", 145);
		Bureaucrat Alice("Alice", 3);
		PresidentialPardonForm form("home");
		Mike.signForm(form);
		Bob.signForm(form);
		Alice.signForm(form);
		Mike.executeForm(form);
		Bob.executeForm(form);
		Alice.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
