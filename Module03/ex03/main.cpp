# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

void print( std::string message );

void testDiamondTrapConstructor( std::string name );
void testDiamondTrapParameters( std::string name );
void testDiamondTrapCopy( void );
void testDiamondTrapWhoAmI( std::string name );
void testDiamondOtherMethods( std::string name );

int main (void)
{
    testDiamondTrapConstructor("Cicero");
    print("_______________________________________________");
	testDiamondTrapParameters("Marco Aurelio");
	print("_______________________________________________");
    testDiamondTrapCopy();
    print("_______________________________________________");
    testDiamondTrapWhoAmI("Thorin");
    print("_______________________________________________");
    testDiamondOtherMethods("Becker");
    print("_______________________________________________");
}

void testDiamondTrapConstructor( std::string name )
{
    print("___________| DiamondTrap Test Constructor |__________");
    DiamondTrap random(name);
}


void testDiamondTrapParameters( std::string name )
{
	print("___________| DiamondTrap Test Initial Values |__________");
	DiamondTrap random(name);

	random.displayData();
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

void testDiamondOtherMethods( std::string name )
{
    print("___________| DiamondTrap Test Other Methods |__________");
    DiamondTrap random(name);

    print("___________| DiamondTrap Test FragTrap's highFivesGuys Method |__________");
    random.highFivesGuys();
    
    print("___________| DiamondTrap Test ScavTrap's guardGate Method |__________");
    random.guardGate();

    random.attack("Case");
}

void print( std::string message )
{
    std::cout << message << std::endl;
}
