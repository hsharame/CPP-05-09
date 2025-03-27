/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:52:51 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/26 11:40:38 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <list>
#include <algorithm>
#include <vector>
#include <deque>

template<typename T>
typename T::iterator	easyfind(T &cont, int find)
{
	typename T::iterator result = std::find(cont.begin(), cont.end(), find);
	if (result == cont.end())
		throw std::out_of_range("No occurrence found");
	return result;
}

template<typename T>
typename T::const_iterator	easyfind(const T &cont, const int find)
{
	typename T::const_iterator result = std::find(cont.begin(), cont.end(), find);
	if (result == cont.end())
		throw std::out_of_range("No occurrence found");
	return result;
}

#endif
