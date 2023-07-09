#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>

class DiamondTrap
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

};

#endif
