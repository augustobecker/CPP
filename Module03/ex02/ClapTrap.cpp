/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:36:52 by acesar-l          #+#    #+#             */
/*   Updated: 2023/07/03 22:48:26 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name )
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " Constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << this->_name << " Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &obj)
{
	std::cout << "ClapTrap " << this->_name << " Copy Constructor called" << std::endl;
	this->_name = obj.getName();
	this->_hitPoints = obj.getHitPoints();
	this->_energyPoints = obj.getEnergyPoints();
	this->_attackDamage = obj.getAttackDamage();
}

ClapTrap& ClapTrap::operator=(ClapTrap &obj)
{
	if (this != &obj)
	{
		std::cout << "ClapTrap " << this->_name << " was replaced, now it is " << obj.getName() << std::endl;
		this->_name = obj.getName();
		this->_hitPoints = obj.getHitPoints();
		this->_energyPoints = obj.getEnergyPoints();
		this->_attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

std::string ClapTrap::getName( void )
{
	return (this->_name);
}

void ClapTrap::setName( std::string name )
{
	this->_name = name;
}

int ClapTrap::getHitPoints( void )
{
	return (this->_hitPoints);
}

void ClapTrap::setHitPoints( int hitPoints )
{
	this->_hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints( void )
{
	return (this->_energyPoints);
}

void ClapTrap::setEnergyPoints( int energyPoints )
{
	this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage( int attackDamage )
{
	int	previousAttackDamage;
	
	previousAttackDamage = this->_attackDamage;
	this->_attackDamage = attackDamage;
	if (this->_attackDamage > previousAttackDamage)
	{
		std::cout << "ClapTrap " << this->_name << " is better armed now. ";
	}
	else if (this->_attackDamage < previousAttackDamage)
	{
		std::cout << "ClapTrap " << this->_name << " is less armed now. ";
	}
	else
		return ;
	std::cout << "Attack Damage is now " << this->_attackDamage << " points!";
	std::cout << std::endl;
}

int	ClapTrap::getAttackDamage( void )
{
	return (this->_attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " can't attack because it is already dead!";
		std::cout << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " can't attack because it doesn't have Energy Points!";
		std::cout << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	if (this->_attackDamage <= 0)
		std::cout << ", causing no damage!";
	else
		std::cout << ", causing " << this->_attackDamage << " points of damage!";
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int	damage;

	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " can't take Damage because it is already dead!";
		std::cout << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " was hit, ";
	if (amount == 0)
		std::cout << "but didn't take any damage! ";
	else
	{
		damage = amount;
		if (damage >= this->_hitPoints)
		{
			damage = this->_hitPoints;
			this->_hitPoints = 0;
		}
		else
			this->_hitPoints -= damage;
		std::cout << "causing " << damage << " points of damage! ";
	}
	std::cout << "Hit Points are now " << this->_hitPoints << "." ;
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	int heal;

	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " can't attack because it doesn't have Energy Points!";
		std::cout << std::endl;
		return ;
	}
	if (!amount)
		return ;
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " was healed and rose from death. ";
	}
	else
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " was healed by " << amount << " Hit points. ";
	}
	heal = amount;
	this->_hitPoints += heal;
	this->_energyPoints--;
	std::cout << "Hit Points are now " << this->_hitPoints << "." ;
	std::cout << std::endl;
}