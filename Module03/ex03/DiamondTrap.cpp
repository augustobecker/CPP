# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name + "_clap_name" ), ScavTrap( name ), FragTrap ( name )
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "DiamondTrap " << _name << " Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap " << _name << " Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap &obj ) : ClapTrap( obj.getName() ), ScavTrap( obj.getName()), FragTrap ( obj.getName() )
{
	_name = obj.getName();
	ClapTrap::_name = obj.getClapName();
	_hitPoints = obj.getHitPoints();
	_energyPoints = obj.getEnergyPoints();
	_attackDamage = obj.getAttackDamage();
	std::cout << "DiamondTrap " << _name << " Copy Constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=( DiamondTrap &obj )
{
	if (this != &obj)
	{
		std::cout << "DiamondTrap " << _name << " was replaced, now it is " << obj.getName() << std::endl;
		_name = obj.getName();
		ClapTrap::_name = obj.getClapName();
		_hitPoints = obj.getHitPoints();
		_energyPoints = obj.getEnergyPoints();
		_attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

void DiamondTrap::setName( std::string name )
{
	_name = name;
}

std::string DiamondTrap::getName( void ) const
{
	return (_name);
}

void DiamondTrap::setClapName( std::string name )
{
	ClapTrap::_name = name;
}

std::string DiamondTrap::getClapName( void ) const
{
	return (ClapTrap::_name);
}

void DiamondTrap::setHitPoints( int hitPoints )
{
	_hitPoints = hitPoints; 
}

int	DiamondTrap::getHitPoints( void ) const
{
	return FragTrap::getHitPoints();
}

void DiamondTrap::setEnergyPoints( int energyPoints )
{
	_energyPoints = energyPoints; 
}

int	DiamondTrap::getEnergyPoints( void ) const
{
	return ScavTrap::getEnergyPoints();
}

void DiamondTrap::setAttackDamage( int attackDamage )
{
	_attackDamage = attackDamage;
}

int	DiamondTrap::getAttackDamage( void ) const
{
	return FragTrap::getAttackDamage();
}

void DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void ) const
{
    std::cout << "I am DiamondTrap " << _name << " son of " << ClapTrap::_name << ", King under the Mountain!" << std::endl;
}
