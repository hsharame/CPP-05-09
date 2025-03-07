/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:15:17 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/07 12:35:23 by hsharame         ###   ########.fr       */
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

void	ShrubberyCreationForm::executeForm() const
{
	std::ofstream	tree((this->_target + "_shrubbery").c_str());
	if (!tree)
	{
		std::cerr << "Can't creat file " << this->_target + "_shrubbery" << std::endl;
		return ;
	}
	tree << "          &&& &&  & &&" << std::endl;
    tree << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
    tree << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    tree << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    tree << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    tree << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    tree << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    tree << "     &&     \\|||" << std::endl;
    tree << "             |||" << std::endl;
    tree << "             |||" << std::endl;
    tree << "             |||" << std::endl;
    tree << "       , -=-~  .-^- _" << std::endl;
	tree.close();
	std::cout << "ShrubberyCreationForm was executed" << std::endl;
}
