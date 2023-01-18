/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:06:05 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/18 17:44:16 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon( std::string type )
{
    this->_type = type;
}

Weapon::~Weapon()
{
    std::cout << _type << " was destroyed" << std::endl;
}

void Weapon::setType( std::string weapon_type )
{
    this->_type = weapon_type;
}

std::string const & Weapon::getType( void )
{
    return (this->_type);
}
