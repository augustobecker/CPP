/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:51:53 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/17 20:08:50 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

int main(void)
{
    Zombie *Jube;
    Zombie Leo("Leo");
    
    Jube = newZombie("Gusto");
    Jube->announce();
    Leo.announce();
    randomChump("Julinho");
    delete(Jube);
    return (0);
}
