/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:05:37 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/18 18:01:46 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA( std::string name, const Weapon& weapon_type )
{
    this->_name = name;
    this->_weapon = weapon_type;
}

HumanA::~HumanA()
{
    std::cout << _name << " died" << std::endl;
}

void HumanA::setWeapon( const Weapon& weapon_type )
{
    this->_weapon = weapon_type;
}

void HumanA::attack( void )
{
    std::cout << _name << " attacks ";
    std::cout << "with their " << this->_weapon.getType();
    std::cout << std::endl;
}
