#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>

class DiamondTrap : public ScavTrap : public FragTrap
{

protected:

	std::string _name;
	int         _hitPoints;
	int         _energyPoints;
	int         _attackDamage;

public:

	DiamondTrap( std::string );
	~DiamondTrap( void );

	DiamondTrap(DiamondTrap &);
	DiamondTrap& operator=(DiamondTrap &);

    void whoAmI( void );
};

#endif
