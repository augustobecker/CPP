/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:36:39 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/17 22:10:05 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
	std::string		value = "HI THIS IS BRAIN";
	std::string*	value_ptr = &value;
	std::string&	value_ref = value;

	std::cout << " Memory address:" << std::endl;
	std::cout << "\tString address:\t\t\t" << &value << std::endl;
	std::cout << "\tAddress held by Pointer:\t" << value_ptr << std::endl;
	std::cout << "\tAddress held by Reference:\t" << &value_ref << std::endl;
	std::cout << std::endl;

	std::cout << " Value:" << std::endl;
	std::cout << "\tString value:\t\t\t" << value << std::endl;
	std::cout << "\tValue pointed by Pointer:\t" << *value_ptr << std::endl;
	std::cout << "\tValue pointed by Reference:\t" << value_ref << std::endl;
	std::cout << std::endl;
}