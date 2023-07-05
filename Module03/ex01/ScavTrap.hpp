#ifndef ScavTrap_HPP
# define ScavTrap_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap
{

private:

	std::string _name;
	int         _hitPoints;
	int         _energyPoints;
	int         _attackDamage;

public:

	ScavTrap( std::string );
	~ScavTrap( void );

	ScavTrap(ScavTrap &);
	ScavTrap& operator=(ScavTrap &);

	std::string getName( void );
	void        setName( std::string );

	int		getHitPoints( void );
	void	setHitPoints( int );

	int		getEnergyPoints( void );
	void	setEnergyPoints( int );

	int		getAttackDamage( void );
	void	setAttackDamage( int );

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif
