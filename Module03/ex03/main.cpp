# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

void print( std::string message );

void testDiamondTrapConstructor( std::string name );
void testDiamondTrapCopy( void );
void testDiamondTrapWhoAmI( std::string name );
void testDiamondOtherMethods( std::string name );

int main (void)
{
    testDiamondTrapConstructor("Cicero");
    print("_______________________________________________");
    testDiamondTrapCopy();
    print("_______________________________________________");
    testDiamondTrapWhoAmI("Thorin");
    print("_______________________________________________");
    testDiamondOtherMethods("Becker");
    print("_______________________________________________");
}

void testDiamondTrapCopy( void )
{
    print("___________| DiamondTrap Test Copy Constructor and Assign Operator |__________");
    DiamondTrap randomGuy("Zuckerberg");
    DiamondTrap strangeGuy("Musk");
    DiamondTrap copyRandomByConstructor(randomGuy);
    DiamondTrap copyRandomByAssign("Default");

    copyRandomByAssign = strangeGuy;
    randomGuy.whoAmI();
    copyRandomByConstructor.whoAmI();
    strangeGuy.whoAmI();
    copyRandomByAssign.whoAmI();
}

void testDiamondTrapWhoAmI( std::string name )
{
    print("___________| DiamondTrap Test Who Am I Method |__________");
    DiamondTrap random(name);
    random.whoAmI();
}

void testDiamondTrapConstructor( std::string name )
{
    print("___________| DiamondTrap Test Constructor |__________");
    DiamondTrap random(name);
}

void testDiamondOtherMethods( std::string name )
{
    print("___________| DiamondTrap Test Other Methods |__________");
    DiamondTrap random(name);

    print("___________| DiamondTrap Test FragTrap's highFivesGuys Method |__________");
    random.highFivesGuys();
    
    print("___________| DiamondTrap Test ScavTrap's guardGate Method |__________");
    random.guardGate();
}

void print( std::string message )
{
    std::cout << message << std::endl;
}
