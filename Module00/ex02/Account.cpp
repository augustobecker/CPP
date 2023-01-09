/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:09:10 by acesar-l          #+#    #+#             */
/*   Updated: 2023/01/09 02:42:43 by acesar-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

static int	Account::getNbAccounts( void )
{
}

static int	Account::getTotalAmount( void )
{
	int	index;
	int	total;

	index = 0;
	total = 0;
	while ( index < _nbAccounts)
	{
		total += Account[index]._amount;
		index++;
	}
	return (total);
}    

static int	Account::getNbDeposits( void )
{
	
}

static int	Account::getNbWithdrawals( void )
{

}

static void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
}

Account::Account( int initial_deposit )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	this->_amount = initial_deposit;
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->getNbDeposits();
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal <= this->_amount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->getNbWithdrawals();
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused";
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->getNbDeposits() << ";";
	std::cout << "withdrawals:" << this->getNbWithdrawals();
}

static void	Account::_displayTimestamp( void )
{
	
}