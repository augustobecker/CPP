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

void debug_info(std::string message);

int main (void)
{
    ClapTrap Duda("Duda");
    ClapTrap Eduarda("Eduarda");

    debug_info("Tries to attack Rafe but with default AttackDamage(0), causing no damage");
    Duda.attack("Rafe");

    debug_info("change AttackDamage to 12");
    Duda.setAttackDamage(12);
    debug_info("Now it causes a damage");
    Duda.attack("Rafe");

    debug_info("change AttackDamage to 2");
    Duda.setAttackDamage(2);
    Duda.attack("Rafe");

    debug_info("change AttackDamage to 0");
    Duda.setAttackDamage(0);
    Duda.attack("Marco");
    Duda.attack("herself");

    debug_info("uses takeDamage method with value 0 and then 8");
    Duda.takeDamage(0);
    Duda.takeDamage(8);

    Duda.attack("Marco");

    debug_info("After suffering 8 points of Damage its hitPoints decrease to 2");
    debug_info("uses takeDamage method with value 3 (More then actual HitPoints = 2)");
    Duda.takeDamage(3);
    Duda.setAttackDamage(11);

    debug_info("Tries to attack even with HitPoints as 0");
    Duda.attack("Marco");

    debug_info("uses beRepaired method with value 5");
    Duda.beRepaired(5);

    Duda.attack("Marco");

    debug_info("uses beRepaired method with value 9");
    Duda.beRepaired(9);

    debug_info("Attacks Rafe until uses all of its Energy Points");
    Duda.attack("Rafe");
    Duda.attack("Rafe");
    Duda.attack("Rafe");

    debug_info("uses takeDamage method with value 19 (More then actual HitPoints = 14)");
    Duda.takeDamage(19);

    debug_info("Tries to attack with no HitPoints");
    Eduarda.attack("Ronnie");

    debug_info("using Copy Assign operator");
    Eduarda = Duda;
    Eduarda.attack("Ronnie");
}

void debug_info(std::string message)
{
    std::cout << '\t' << "[debug_info: " << message <<  "]" << std::endl;
}