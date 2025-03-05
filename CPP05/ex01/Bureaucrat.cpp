/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:27:40 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/05 13:13:01 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

void		Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream&	operator<<(std::ostream &stream, Bureaucrat const& b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return stream;
}
