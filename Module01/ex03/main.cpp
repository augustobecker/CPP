/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:06:14 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/18 17:45:06 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main( void )
{
	Weapon bow = Weapon("recurve bow");

	HumanA augusto = HumanA("Augusto", bow);
	HumanB amanda = HumanB("Amanda");
	augusto.attack();
	bow.setType("longbow");
	augusto.attack();
	amanda.setWeapon(&bow);
	amanda.attack();
	bow.setType("recurve bow");
	amanda.attack();
}

void explanation( void )
{
	std::cout << std::endl << "Explaining" << std::endl;
	std::cout << "\tHuman A will always be armed, ";
	std::cout << "so we can use a reference to Weapon, ";
	std::cout << "since it will never be NULL." << std::endl;
	std::cout << "\tOn the other hand, Human B needds a pointer ";
	std::cout << "to Weapon, since it can be NULL (unarmed)." << std::endl;
	std::cout << std::endl;
}
