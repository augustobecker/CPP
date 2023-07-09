# include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " Constructor called" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap " << this->_name << " Destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap &obj) : ClapTrap( obj.getName() )
{
	this->_name = obj.getName();
	this->_hitPoints = obj.getHitPoints();
	this->_energyPoints = obj.getEnergyPoints();
	this->_attackDamage = obj.getAttackDamage();
	std::cout << "FragTrap " << this->_name << " Copy Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap &obj)
{
	if (this != &obj)
	{
		std::cout << "FragTrap " << this->_name << " was replaced, now it is " << obj.getName() << std::endl;
		this->_name = obj.getName();
		this->_hitPoints = obj.getHitPoints();
		this->_energyPoints = obj.getEnergyPoints();
		this->_attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name;
	std::cout << " high five was accepted";
	std::cout << std::endl;
}
