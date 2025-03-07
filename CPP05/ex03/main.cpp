/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:14:18 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/07 16:15:24 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	try
	{
		Bureaucrat Bob("Bob", 4);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bob.signForm(*rrf);
		Bob.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	try
	{
		Bureaucrat Alice("Alice", 145);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Alice.signForm(*rrf);
		Alice.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	try
	{
		Bureaucrat Paul("Paul", 100);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "arbre");
		Paul.executeForm(*rrf);
		Paul.signForm(*rrf);
		Paul.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	try
	{
		Bureaucrat Paul("Paul", 100);
		Bureaucrat Louis("Louis", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("president pardon", "Trump");
		Paul.signForm(*rrf);
		Louis.signForm(*rrf);
		Louis.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	try
	{
		Bureaucrat Sarah("Sarah", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("CERFA", "form");
		Sarah.signForm(*rrf);
		Sarah.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
