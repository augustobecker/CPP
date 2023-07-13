/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:36:52 by acesar-l          #+#    #+#             */
/*   Updated: 2023/07/03 22:48:26 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " Constructor called" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap " << _name << " Destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap &obj) : ClapTrap( obj.getName() )
{
	std::cout << "FragTrap " << _name << " Copy Constructor called" << std::endl;
	*this = obj;
}

FragTrap& FragTrap::operator=(FragTrap &obj)
{
	if (this != &obj)
	{
		std::cout << "FragTrap " << _name << " was replaced, now it is " << obj.getName() << std::endl;
		_name = obj.getName();
		_hitPoints = obj.getHitPoints();
		_energyPoints = obj.getEnergyPoints();
		_attackDamage = obj.getAttackDamage();
	}
	return (*this);
}

void FragTrap::highFivesGuys( void ) const
{
	std::cout << "FragTrap " << _name;
	std::cout << " high five was accepted";
	std::cout << std::endl;
}
