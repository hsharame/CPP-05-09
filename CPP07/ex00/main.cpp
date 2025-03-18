/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:02:26 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/18 16:00:55 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) 
{
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << std::string(50, '_') << std::endl << std::endl;
	{
		char c = '*';
		char c1 = c;
		std::cout << "c = " << c << " ; c1 = " << c1 << std::endl;
		std::cout << "min(c, c1): " << min(c, c1) << std::endl;
		c1++;
		std::cout << "c = " << c << " ; c1 = " << c1 << std::endl;
		std::cout << "min(c, c1): " << min(c, c1) << std::endl;
		std::cout << "max(c, c1): " << max(c, c1) << std::endl;
	}
	return 0;
}
