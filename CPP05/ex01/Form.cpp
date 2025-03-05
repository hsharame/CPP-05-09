/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:01:17 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/05 15:57:11 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(1),
	_gradeToExecute(1) {}

Form::Form(std::string name, int gradeSign, int gradeExec) :
	_name(name), _signed(false), _gradeToSign(gradeSign), 
	_gradeToExecute(gradeExec)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form& Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

std::string	Form::getName() const { return this->_name; }

bool		Form::getSigned() const { return this->_signed; }

int			Form::getGradeToSign() const { return this->_gradeToSign; }

int 		Form::getGradeToExecute() const { return this->_gradeToExecute; }

void		Form::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high!";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low!";
}

std::ostream&	operator<<(std::ostream &stream, Form const& f)
{
	std::string	status = "non";
	if (f.getSigned())
		status = "yes";
	stream << "Form: " << f.getName() << ". Signed: " << status <<
	". Grade required to sign: " << f.getGradeToSign() <<
	". Grade required to execute: " << f.getGradeToExecute() << ".";
	return stream;
}
