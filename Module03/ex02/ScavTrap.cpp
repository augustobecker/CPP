/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:36:52 by acesar-l          #+#    #+#             */
/*   Updated: 2023/07/03 22:48:26 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " Constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap " << _name << " Destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj) : ClapTrap( obj.getName() )
{
	std::cout << "ScavTrap " << this->_name << " Copy Constructor called" << std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=(ScavTrap &obj)
{
	if (this != &obj)
	{
		std::cout << "ScavTrap " << _name << " was replaced, now it is " << obj.getName() << std::endl;
		_name = obj.getName();
		_hitPoints = obj.getHitPoints();
		_energyPoints = obj.getEnergyPoints();
		_attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name;
		std::cout << " can't attack because it is already dead!";
		std::cout << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name;
		std::cout << " can't attack because it doesn't have Energy Points!";
		std::cout << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " strikes " << target;
	if (_attackDamage <= 0)
		std::cout << ", causing no damage!";
	else
		std::cout << ", causing " << _attackDamage << " points of damage!";
	std::cout << std::endl;
}

void ScavTrap::guardGate( void ) const
{
	std::cout << "ScavTrap " << _name;
	std::cout << " is now on Gate Keeper mode!";
	std::cout << std::endl;
}
