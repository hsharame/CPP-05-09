/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:01:17 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/07 12:45:31 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(1),
	_gradeToExecute(1) {}

AForm::AForm(std::string name, int gradeSign, int gradeExec) :
	_name(name), _signed(false), _gradeToSign(gradeSign), 
	_gradeToExecute(gradeExec)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm& AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

std::string	AForm::getName() const { return this->_name; }

bool		AForm::getSigned() const { return this->_signed; }

int			AForm::getGradeToSign() const { return this->_gradeToSign; }

int 		AForm::getGradeToExecute() const { return this->_gradeToExecute; }

void		AForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->_signed = true;
}

void		AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	if (!this->_signed)
		throw FormNotSigned();
	this->executeForm();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char*	AForm::FormNotSigned::what() const throw()
{
	return "Form cannot be executed because it is not signed";
}

std::ostream&	operator<<(std::ostream &stream, AForm const& f)
{
	std::string	status = "non";
	if (f.getSigned())
		status = "yes";
	stream << "AForm: " << f.getName() << ". Signed: " << status <<
	". Grade required to sign: " << f.getGradeToSign() <<
	". Grade required to execute: " << f.getGradeToExecute() << ".";
	return stream;
}
