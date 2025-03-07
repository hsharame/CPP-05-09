/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:01:15 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/07 12:15:25 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class	AForm
{
	private:
		std::string const _name;
		bool		_signed;
		int const	_gradeToSign;
		int const	_gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExec);
		virtual ~AForm();
		AForm(AForm const &src);
		AForm& operator=(AForm const &rhs);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat const& b);
		void		execute(Bureaucrat const & executor) const;
		virtual void	executeForm() const = 0;

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
		class FormNotSigned: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &stream, AForm const& f);

#endif
