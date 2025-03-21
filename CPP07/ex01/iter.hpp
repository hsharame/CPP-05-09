/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:25:05 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/21 13:31:56 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* array, unsigned int length, void (*func)(T&)) 
{
	for (unsigned int i = 0; i < length; i++)
		func(array[i]);
}

template<typename T>
void iter(const T* array, unsigned int length, void (*func)(const T&)) 
{
	for (unsigned int i = 0; i < length; i++)
		func(array[i]);
}

template<typename U>
void	display(U &element)
{
	std::cout << element << std::endl;
}

template<typename U>
void	display_espace(U &element)
{
	std::cout << element << " ";
}

#endif
