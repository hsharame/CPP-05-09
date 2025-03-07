/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:14:18 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/07 16:27:32 by hsharame         ###   ########.fr       */
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
		std::cout << *rrf << std::endl;
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
		std::cout << *rrf << std::endl;
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
		std::cout << *rrf << std::endl;
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
		std::cout << *rrf << std::endl;
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
		std::cout << *rrf << std::endl;
		Sarah.signForm(*rrf);
		Sarah.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
