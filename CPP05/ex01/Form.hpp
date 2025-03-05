/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:01:15 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/05 15:38:37 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class	Form
{
	private:
		std::string const _name;
		bool		_signed;
		int const	_gradeToSign;
		int const	_gradeToExecute;

	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		~Form();
		Form(Form const &src);
		Form& operator=(Form const &rhs);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat const& b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &stream, Form const& f);

#endif
