/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:25:05 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/18 17:20:13 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* array, unsigned int length, void (*func)(T&)) 
{
	unsigned int	real_size = 0;
	while (array[real_size])
		real_size++;
	if (length > real_size)
		length = real_size;
	for (unsigned int i = 0; i < length; i++)
		func(array[i]);
}

template<typename U>
void	display(U &element)
{
	std::cout << element << std::endl;
}

#endif
