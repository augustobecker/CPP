# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name )
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "DiamondTrap " << this->_name << " Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap " << this->_name << " Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &obj)
{
	std::cout << "DiamondTrap " << this->_name << " Copy Constructor called" << std::endl;
	//this->_name = obj.getName();
	//this->_hitPoints = obj.getHitPoints();
	//this->_energyPoints = obj.getEnergyPoints();
	//this->_attackDamage = obj.getAttackDamage();
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap &obj)
{
	if (this != &obj)
	{
		//std::cout << "DiamondTrap " << this->_name << " was replaced, now it is " << obj.getName() << std::endl;
		//this->_name = obj.getName();
		//this->_hitPoints = obj.getHitPoints();
		//this->_energyPoints = obj.getEnergyPoints();
		//this->_attackDamage = obj.getAttackDamage();
	}
	return (*this);
}
