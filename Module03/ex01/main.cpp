/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:41:17 by acesar-l          #+#    #+#             */
/*   Updated: 2023/07/03 22:44:20 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "ClapTrap.hpp"

int main (void)
{
    ClapTrap Duda("Duda");
    ClapTrap Eduarda("Eduarda");

    Duda.attack("Rafe");
    Duda.setAttackDamage(12);
    Duda.attack("Rafe");
    Duda.setAttackDamage(2);
    Duda.attack("Rafe");
    Duda.setAttackDamage(0);
    Duda.attack("Marco");
    Duda.attack("herself");
    Duda.takeDamage(0);
    Duda.takeDamage(8);
    Duda.attack("Marco");
    Duda.takeDamage(3);
    Duda.setAttackDamage(11);
    Duda.attack("Marco");
    Duda.beRepaired(5);
    Duda.attack("Marco");
    Duda.beRepaired(9);
    Duda.takeDamage(19);
    Eduarda.attack("Ronnie");
    Eduarda = Duda;
    Eduarda.attack("Ronnie");
}