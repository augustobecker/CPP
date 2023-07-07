#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:

	ScavTrap( std::string );
	~ScavTrap( void );

	ScavTrap(ScavTrap &);
	ScavTrap& operator=(ScavTrap &);

	void attack(const std::string& target);
	void guardGate( void );

};

#endif
