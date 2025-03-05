/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:26:40 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/05 12:55:01 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		std::string	const _name;
		int	_grade;
		
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat& operator=(Bureaucrat const &rhs);

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

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

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const& b);

#endif
