/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:51:33 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/07 16:17:38 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &src) 
{
	*this = src;
}

Intern& Intern::operator=(Intern const &rhs)
{
	(void) rhs;
	return *this;
}

AForm*	Intern::makeForm(std::string name, std::string target) const
{
	AForm *result;
	std::string forms[3] = {"president pardon", "robotomy request", "shrubbery creation"};
	int index(-1);
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			index = i;
			break;
		}
	}
	switch(index)
	{
		case 0:
			result = new PresidentialPardonForm(target);
			break;
		case 1:
			result = new RobotomyRequestForm(target);
			break;
		case 2:
			result = new ShrubberyCreationForm(target);
			break;
		default:
			throw FormDoesntExist();
	}
	std::cout << "Intern creates " << name << std::endl;
	return result;
}

const char*	Intern::FormDoesntExist::what() const throw()
{
	return "The form name doesn't exist";
}
