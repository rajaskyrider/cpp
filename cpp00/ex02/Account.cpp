/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:54:05 by rpandipe          #+#    #+#             */
/*   Updated: 2024/11/27 23:20:48 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	//accounts:8;total:20049;deposits:0;withdrawals:0
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
			  << "total:" << Account::_totalAmount << ";"
			  << "deposits:" << Account::_totalNbDeposits << ";"
			  << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account (int initial_deposit)
{
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_accountIndex = Account::_nbAccounts;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";"
			  << "created" << std::endl;
	Account::_nbAccounts += 1;
}

Account::Account (void)
{
	this->_amount = 0;
	this->_accountIndex = Account::_nbAccounts;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "amount:" << this->_amount << ";"
			<< "created" << std::endl;
	Account::_nbAccounts += 1;
}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";"
			  << "closed" << std::endl;
	Account::_nbAccounts -= 1;
}

void	Account::makeDeposit( int deposit )
{
	//index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << this->_amount << ";"
			  << "deposit:" << deposit << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << "amount:" << this->_amount << ";"
			  << "nb_deposits:" << this->_nbDeposits << std::endl;
	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	//index:0;p_amount:47;withdrawal:refused
	//index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << this->_amount << ";";
	if (this->_amount - withdrawal >= 0)
	{
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		std::cout << "withdrawal:" << withdrawal << ";"
			  	  << "amount:" << this->_amount << ";"
			  	  << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << this->_amount << ";"
			  << "deposits:" << this->_nbDeposits << ";"
			  << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{
	std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    char buffer[20];
	
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
    std::cout << "[" << buffer << "] ";
}