# include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " Constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap " << this->_name << " Destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj) : ClapTrap( obj.getName() )
{
	this->_name = obj.getName();
	this->_hitPoints = obj.getHitPoints();
	this->_energyPoints = obj.getEnergyPoints();
	this->_attackDamage = obj.getAttackDamage();
	std::cout << "ScavTrap " << this->_name << " Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap &obj)
{
	if (this != &obj)
	{
		std::cout << "ScavTrap " << this->_name << " was replaced, now it is " << obj.getName() << std::endl;
		this->_name = obj.getName();
		this->_hitPoints = obj.getHitPoints();
		this->_energyPoints = obj.getEnergyPoints();
		this->_attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name;
		std::cout << " can't attack because it is already dead!";
		std::cout << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name;
		std::cout << " can't attack because it doesn't have Energy Points!";
		std::cout << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " strikes " << target;
	if (this->_attackDamage <= 0)
		std::cout << ", causing no damage!";
	else
		std::cout << ", causing " << this->_attackDamage << " points of damage!";
	std::cout << std::endl;
}

void ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name;
	std::cout << " is now on Gate Keeper mode!";
	std::cout << std::endl;
}
