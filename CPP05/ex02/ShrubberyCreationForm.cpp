/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanna <hanna@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:15:17 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/06 11:32:49 by hanna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF", 145, 137),
    _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
    AForm("SCF", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()),
    _target(src._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void	ShrubberyCreationForm::executeForm()
{

}