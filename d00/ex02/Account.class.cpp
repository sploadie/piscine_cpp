/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 18:04:37 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/05 09:56:44 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <time.h>
#include <iostream>

// Public

typedef Account		t;

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}
int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}
int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
	return;
}

Account::Account( int initial_deposit ) {
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::_nbAccounts;
	this->_timesAmountChecked = 0;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return;
}
Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return;
}

void	Account::makeDeposit( int deposit ) {
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
	return;
}
bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if ( withdrawal > this->_amount ) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}
int		Account::checkAmount( void ) const {
	this->_timesAmountChecked++;
	return this->_amount;
}
void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return;
}


// Private

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void ) {
	char timestamp[256];
	time_t curr_time = time(NULL);
	struct tm *my_time = localtime(&curr_time);

	strftime(timestamp, sizeof(timestamp), "[%G%m%d_%H%M%S] ", my_time);
	std::cout << timestamp;
	// std::cout << "[20150406_153629] ";
}

// Account( void );
