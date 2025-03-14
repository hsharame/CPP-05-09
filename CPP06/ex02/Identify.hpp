/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:33:51 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/14 14:04:23 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

class Identify
{
	private:
		Identify();
		~Identify();
		Identify(Identify const &src);
		Identify& operator=(Identify const &rhs);

	public:
		static Base* generate(void);
		static void identify(Base* p);
		static void identify(Base& p);

		class BadCastException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
