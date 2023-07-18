#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
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

	std::string getName( void ) const ;
	void		setName( std::string );

	std::string getClapName( void ) const;
	void		setClapName( std::string );

	int			getHitPoints( void ) const;
	void		setHitPoints( int );

	int			getEnergyPoints( void ) const;
	void		setEnergyPoints( int );

	int			getAttackDamage( void ) const;
	void		setAttackDamage( int );

    void whoAmI( void ) const;
	void attack( const std::string& target );

};

#endif
