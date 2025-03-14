/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:28:50 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/14 13:15:32 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer const &src);
		Serializer& operator=(Serializer const &rhs);

	public:
		static uintptr_t 	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
