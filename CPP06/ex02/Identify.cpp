/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:36:51 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/14 14:09:13 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Identify::Identify() {}

Identify::~Identify() {}

Identify::Identify(Identify const &src) { *this = src; }

Identify& Identify::operator=(Identify const &rhs) { 
	(void) rhs;
	return *this; }

Base* Identify::generate(void)
{
	Base* result;
	srand(static_cast<unsigned int>(time(NULL)));
	if (rand() % 2 == 0)
		result = new A;
	else if (rand() % 3 == 0)
		result = new B;
	else
		result = new C;
	return result;
}

void Identify::identify(Base* p)
{
	std::cout << "The actual type of the pointed object: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void Identify::identify(Base& p)
{
	std::cout << "The actual type of the referenced object: ";
	try
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			static_cast<void>(dynamic_cast<B&>(p));
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				static_cast<void>(dynamic_cast<C&>(p));
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				throw BadCastException();
			}
		}
	}
}

const char *Identify::BadCastException::what() const throw()
{
	return "Unknown type";
}
