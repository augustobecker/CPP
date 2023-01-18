/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:04:50 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/18 17:41:45 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{

private:

    std::string _type;

public:

    Weapon( void );
    Weapon( std::string weapon_type );
    ~Weapon( void );

    void setType( std::string weapon_type );
    std::string const & getType( void );

};

#endif