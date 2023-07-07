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
# include "ScavTrap.hpp"

int main (void)
{
    ClapTrap Duda("Duda");
    ScavTrap Lala("Lala");
    ScavTrap Laiza(Lala);
    ScavTrap Andrea("Andrea");

    Laiza.attack("Rafe");
    Lala.attack("Augusto");
    Lala.setAttackDamage(5);
    Laiza.attack("Rafe");
    Lala.attack("Augusto");
    Lala.guardGate();
    //Duda.guardGate();
    Lala.attack(Duda.getName());
    Duda.takeDamage(Lala.getAttackDamage());
    Duda.attack(Lala.getName());
    Lala.takeDamage(Duda.getAttackDamage());
    Duda.attack(Lala.getName());
    Lala.takeDamage(Duda.getAttackDamage());
    Lala.attack(Duda.getName());
    Duda.takeDamage(Lala.getAttackDamage());
    Duda.attack(Lala.getName());
    Laiza = Andrea;
    Laiza.attack("Rafe");
    Lala.attack("Augusto");
    Laiza.setName("Laiza");
}