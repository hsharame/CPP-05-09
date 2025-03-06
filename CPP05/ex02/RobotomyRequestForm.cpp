/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanna <hanna@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:23:50 by hanna             #+#    #+#             */
/*   Updated: 2025/03/06 11:32:43 by hanna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRF", 72, 45),
    _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("RRF", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()),
    _target(src._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

void	RobotomyRequestForm::executeForm()
{

}