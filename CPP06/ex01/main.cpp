/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <hsharame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:47:25 by hsharame          #+#    #+#             */
/*   Updated: 2025/03/14 13:11:09 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data* data = new Data;
	Data* data2 = new Data;
	data->n = 42;
	data->f = 42.42f;
	data->str = "Test";
	
	std::cout << "data: " << data << std::endl;
	std::cout << "data2: " << data2 << std::endl;
	uintptr_t raw = Serializer::serialize(data);
	uintptr_t raw2 = Serializer::serialize(data2);
	uintptr_t raw3 = Serializer::serialize(NULL);
	std::cout << "uintptr of data: " << raw << std::endl;
	std::cout << "uintptr of data2: " << raw2 << std::endl;
	std::cout << "uintptr of null data: " << raw3 << std::endl;
	std::cout << "data after deserialize: " << Serializer::deserialize(raw) << std::endl;
	std::cout << "data2 after deserialize: " << Serializer::deserialize(raw2) << std::endl;
	std::cout << "null after deserialize: " << Serializer::deserialize(raw3) << std::endl;

	delete data;
	delete data2;
	return 0;
}
