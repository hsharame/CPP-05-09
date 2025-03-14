/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/14 13:51:37 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main(void)
{
	Base* base = Identify::generate();
	Identify::identify(base);
	Identify::identify(*base);
	delete base;
	return 0;
}
