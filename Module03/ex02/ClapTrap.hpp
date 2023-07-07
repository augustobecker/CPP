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
