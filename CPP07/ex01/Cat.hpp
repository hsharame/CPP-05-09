/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:29:04 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/19 12:38:05 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "iostream"

class Cat 
{
	public:
		Cat();
		Cat(std::string name);
		~Cat();
		Cat(Cat const &src);
		Cat& operator=(Cat const &rhs);
		void makeSound() const;
		std::string getName(void) const;

	private:
		std::string _name;
};

std::ostream&	operator<<(std::ostream &stream, Cat const& value);

#endif
