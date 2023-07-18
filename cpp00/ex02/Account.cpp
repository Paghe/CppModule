/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:47:55 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/11 12:55:49 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "created" << std::endl;
	
}


int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	std::time_t	currentTime = std::time(NULL);
	std::cout << "[" << std::setw(4) << std::setfill('0') << 1900 + std::localtime(&currentTime)->tm_year
			  << std::setw(2) << 1 + std::localtime(&currentTime)->tm_mon
			  << std::setw(2) << std::localtime(&currentTime)->tm_mday
			  << "_"
			  << std::setw(2) << std::localtime(&currentTime)->tm_hour
			  << std::setw(2) << std::localtime(&currentTime)->tm_min
			  << std::setw(2) << std::localtime(&currentTime)->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';'
			  << "total:" << getTotalAmount() << ';'
			  << "deposits:" << getNbDeposits() << ';'
			  << "withdraws:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	this->_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > this->_amount)
		return (false);
	else
	{
		this->_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
	}	
	return (true);
}

int		Account::checkAmount(void) const
{
	return(this->_amount);	
}

void	Account::displayStatus(void)const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
				<<"p_amount:" << this->_amount << ';'
				<<"deposit:" << this->_nbDeposits
				<<"amount:" << this->_amount << ';'
				<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

Account::~Account(void)
{	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "closed" << std::endl;
}
