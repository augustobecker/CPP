/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:04:40 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/18 18:00:30 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    
private:

    std::string _name;
    Weapon      *_weapon;

public:

    HumanB( std::string name );
    HumanB( std::string name, Weapon *weapon );
    ~HumanB( void );

    void setWeapon( Weapon *weapon );

    void attack( void );

};

#endif