/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:15:12 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/05 16:20:09 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string name, int gradeSign, int gradeExec);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const &rhs);
};

#endif
