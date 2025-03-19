/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:50:48 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/19 14:42:18 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

class BadIndexException : public std::exception
{
	public:
	const char *what() const throw() { return "Index is out of bounds"; }
};

template<typename T>
class Array
{
	public:
	Array() : _size(0) { _array = 0; }
	
	Array(unsigned int n) : _size(n) {
		if (n > 0)
		{
			_array = new T[n]();
		}
		else
			_array = 0;
	}
	
	~Array() { delete [] _array; }
	
	Array(Array const &src) {
		this->_size = src._size;
		if (_size > 0)
			this->_array = new T[_size]();
		else
			this->_array = 0;
		for (unsigned int i = 0; i < src._size; i++)
			this->_array[i] = src._array[i];
	}
	
	Array& operator=(Array const &rhs) {
		if (this != &rhs)
		{
			delete [] this->_array;
			this->_size = rhs._size;
			if (_size > 0)
				this->_array = new T[_size]();
			else
				this->_array = 0;
			for (unsigned int i = 0; i < rhs._size; i++)
				this->_array[i] = rhs._array[i];
		}
		return *this;
	}
	
	unsigned int	size(void) const { return this->_size; }


	T	&operator[](unsigned int i)
	{
		if (i >= this->size())
			throw BadIndexException();
		return _array[i];
	}
	
	const T	&operator[](unsigned int i) const
	{
		if (i >= this->size())
			throw BadIndexException();
		return _array[i];
	}
	

	private:
		T* _array;
		unsigned int _size;
};


#endif
