#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{

protected:

	std::string _name;
	int         _hitPoints;
	int         _energyPoints;
	int         _attackDamage;

public:

	ClapTrap( std::string );
	~ClapTrap( void );

	ClapTrap(ClapTrap &);
	ClapTrap& operator=(ClapTrap &);

	std::string getName( void ) const ;
	void        setName( const std::string );

	int		getHitPoints( void ) const;
	void	setHitPoints( const int );

	int		getEnergyPoints( void ) const;
	void	setEnergyPoints( const int );

	int		getAttackDamage( void ) const;
	void	setAttackDamage( const int );

	void attack( const std::string& );
	void takeDamage( const unsigned int );
	void beRepaired( const unsigned int );

	void displayData( void ) const;

};

#endif
