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
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "ClapTrap " << _name << " Constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << _name << " Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &obj)
{
	*this = obj;
}

ClapTrap& ClapTrap::operator=(ClapTrap &obj)
{
	if (this != &obj)
	{
		std::cout << "ClapTrap " << _name << " was replaced, now it is " << obj.getName() << std::endl;
		_name = obj.getName();
		_hitPoints = obj.getHitPoints();
		_energyPoints = obj.getEnergyPoints();
		_attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

std::string ClapTrap::getName( void ) const
{
	return (_name);
}

void ClapTrap::setName( const std::string name )
{
	_name = name;
}

int ClapTrap::getHitPoints( void ) const
{
	return (_hitPoints);
}

void ClapTrap::setHitPoints( const int hitPoints )
{
	_hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints( void ) const
{
	return (_energyPoints);
}

void ClapTrap::setEnergyPoints( const int energyPoints )
{
	_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage( const int newAttackDamage )
{
	int	previousAttackDamage;
	
	previousAttackDamage = _attackDamage;
	_attackDamage = newAttackDamage;
	if (_attackDamage > previousAttackDamage)
	{
		std::cout << "ClapTrap " << _name << " is better armed now. ";
	}
	else if (_attackDamage < previousAttackDamage)
	{
		std::cout << "ClapTrap " << _name << " is less armed now. ";
	}
	else
		return ;
	std::cout << "Attack Damage is now " << _attackDamage << " points!";
	std::cout << std::endl;
}

int	ClapTrap::getAttackDamage( void ) const
{
	return (_attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " can't attack because it is already dead!";
		std::cout << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " can't attack because it doesn't have Energy Points!";
		std::cout << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target;
	if (_attackDamage <= 0)
		std::cout << ", causing no damage!";
	else
		std::cout << ", causing " << _attackDamage << " points of damage!";
	std::cout << std::endl;
}

void ClapTrap::takeDamage( const unsigned int amount )
{
	int	damage;

	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " can't take Damage because it is already dead!";
		std::cout << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " was hit, ";
	if (amount == 0)
		std::cout << "but didn't take any damage! ";
	else
	{
		damage = amount;
		if (damage >= _hitPoints)
		{
			damage = _hitPoints;
			_hitPoints = 0;
		}
		else
			_hitPoints -= damage;
		std::cout << "causing " << damage << " points of damage! ";
	}
	std::cout << "Hit Points are now " << _hitPoints << "." ;
	std::cout << std::endl;
}

void ClapTrap::beRepaired( const unsigned int amount )
{
	int heal;

	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " can't attack because it doesn't have Energy Points!";
		std::cout << std::endl;
		return ;
	}
	if (!amount)
		return ;
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " was healed and rose from death. ";
	}
	else
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " was healed by " << amount << " Hit points. ";
	}
	heal = amount;
	_hitPoints += heal;
	_energyPoints--;
	std::cout << "Hit Points are now " << _hitPoints << "." ;
	std::cout << std::endl;
}