/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:05:59 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/18 18:00:59 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string name )
{
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::HumanB( std::string name, Weapon& weapon_type )
{
    this->_name = name;
    this->_weapon = &weapon_type;
}

HumanB::~HumanB()
{
    std::cout << _name << " died" << std::endl;
}

void HumanB::setWeapon( Weapon& weapon )
{
    this->_weapon = &weapon;
}

void HumanB::attack( void )
{
    if (this->_weapon == NULL)
    {
        std::cout << _name << " is unarmed ";
        std::cout << std::endl;
        return;
    }
    std::cout << _name << " attacks ";
    std::cout << "with their " << this->_weapon->getType();
    std::cout << std::endl;
}
