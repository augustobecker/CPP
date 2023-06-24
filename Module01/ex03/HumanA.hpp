/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:02:50 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/18 18:00:22 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include "HumanA.hpp"
# include "Weapon.hpp"

class HumanA
{
private:

    std::string     _name;
    Weapon          _weapon;

public:

    HumanA( std::string name, const Weapon& weapon_type );
    ~HumanA( void );

    void setWeapon( const Weapon& weapon_type );

    void attack( void );
};

#endif