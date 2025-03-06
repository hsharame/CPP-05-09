/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanna <hanna@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:23:56 by hanna             #+#    #+#             */
/*   Updated: 2025/03/06 11:32:37 by hanna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF", 25, 5),
    _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    AForm("PPF", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()),
    _target(src._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void	PresidentialPardonForm::executeForm()
{

}