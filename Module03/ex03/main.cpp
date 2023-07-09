# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

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