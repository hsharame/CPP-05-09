/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:30:11 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/19 12:40:43 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {}

Cat::Cat(std::string name) : _name(name) {}

Cat::~Cat() {}

Cat::Cat(Cat const &src)
{
	*this = src;
}

Cat& Cat::operator=(Cat const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void		Cat::makeSound() const
{
	std::cout << "Meow meow !" << std::endl;
}

std::string	Cat::getName(void) const
{
	return this->_name;
}

std::ostream&	operator<<(std::ostream &stream, Cat const& value)
{
	stream << "Je suis un petit chat et je m'appelle " << value.getName() << std::endl;
	value.makeSound();
	return stream;
}

