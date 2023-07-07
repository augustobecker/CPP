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
# include "FragTrap.hpp"

void testMessage( std::string testName, std::string testDescription );

void testFragTrapCreate( std::string name );
void testFragTrapCopy( std::string name );
void testFragTrapActions( std::string name );

int main (void)
{
    std::cout << "******| FRAPTRAP INIT TESTS |*******" << std::endl;
    testFragTrapCreate("Diego");
    std::cout << std::endl << "******| FRAPTRAP COPY (CONSTRUCTOR AND ASSIGN) TESTS |*******" << std::endl;
    testFragTrapCopy("Daniel");
    std::cout << std::endl << "******| FRAPTRAP MEMBER FUNCTION TESTS |*******" << std::endl;
    testFragTrapActions("Bruce");
}

void testFragTrapActions( std::string name )
{
    FragTrap random(name);

    testMessage("FlapTrap implements its own function", "highFivesGuys()");
    random.highFivesGuys();

    testMessage("FlapTrap doesn't implement Attack", "FlapTrap inherits attack from ClapTrap");
    random.attack("Andreas Pereira");

    testMessage("FragTrap dies", "It will take 27 damage points until die, then it can't be attacked anymore");
    for (int i=1; i <= 5; i++)
        random.takeDamage(27);

    testMessage("FlapTrap tries to attack even when it's dead", "");
    random.attack("Andreas Pereira");

    testMessage("FlapTrap repaired", "FlapTrap inherits heal from ClapTrap");
    random.beRepaired(63);

    random.setEnergyPoints(100);
    testMessage("FragTrap Energy Points til end", "It must attack 100 times and then fail due to the lack of Energy Points");
    for (int i=1; i <= 102; i++)
    {
        std::cout << "[ " << i << "] ";
        random.attack("Leo DiCaprio");
    }

    std::cout << std::endl;
    std::cout << "\t* FragTrap info: " << std::endl;
    random.displayData();

}

void testFragTrapCreate( std::string name )
{
    testMessage("Creating a FragTrap", "It must call ClapTrap Constructor first and then FragTrap Constructor");
    FragTrap random(name);

    testMessage("Initialization of a FragTrap", "Hit points (100), Energy points (100), Attack damage (30)");
    random.displayData();

    testMessage("Destroying a FragTrap", "It must call FragTrap Destructor and then ClapTrap Destructor");
}

void testFragTrapCopy( std::string name )
{
    FragTrap random(name);

    testMessage("Creating a FragTrap via Copy Constructor", "It must call ClapTrap Constructor first and then FragTrap Copy Constructor");
    FragTrap copyRandom(random);

    std::cout << std::endl;
    std::cout << "\t* Original FragTrap : " << std::endl;
    random.displayData();
    std::cout << std::endl;
    std::cout << "\t& Copy FragTrap : " << std::endl;
    copyRandom.displayData();

    testMessage("Set Original FragTrap to", "Hit points (66), Energy points (42), Attack damage (9)");
    random.setHitPoints(66);
    random.setEnergyPoints(42);
    random.setAttackDamage(9);

    testMessage("Set Copy FragTrap name to Eleven", "");
    copyRandom.setName("Eleven");

    std::cout << std::endl;

    std::cout << "\t* Original FragTrap : " << std::endl;
    random.displayData();

    std::cout << std::endl;

    std::cout << "\t& Copy FragTrap : " << std::endl;
    copyRandom.displayData();

    testMessage("Assign Copy FragTrap to Original", "");
    copyRandom = random;

    std::cout << std::endl;

    std::cout << "\t* Original FragTrap : " << std::endl;
    random.displayData();

    std::cout << std::endl;

    std::cout << "\t& Copy FragTrap : " << std::endl;
    copyRandom.displayData();

    std::cout << std::endl;
}


void testMessage( std::string testName, std::string testDescription )
{
    std::cout << std::endl << "\t| * | " << testName  << std::endl;
    if (!testDescription.empty())
        std::cout << "\t| ? | " << testDescription  << std::endl;
}
