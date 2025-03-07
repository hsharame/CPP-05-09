/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:51:30 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/07 16:16:41 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
	Intern();
	~Intern();
	Intern(Intern const &src);
	Intern& operator=(Intern const &rhs);

	AForm*	makeForm(std::string name, std::string target) const;

	class FormDoesntExist : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#endif
