#include "Account.hpp"
#include <ctime>
#include <iostream>

int  Account::_nbAccounts = 0;
int  Account::_totalAmount = 0;
int  Account::_totalNbDeposits = 0;
int  Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit) : _amount(initial_deposit) , _nbDeposits(0), _nbWithdrawals(0)  {
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
}

Account::~Account() {

}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

int	Account::checkAmount(void) const {
	return (_amount);
}

void	Account::_displayTimestamp() {
	std::time_t	current_time;
	std::tm	*current_time_p;
	char	date[11];
	char	clock[9];

	std::time(&current_time);
	current_time_p = localtime(&current_time);
	std::strftime(date, 11, "%Y-%m-%d", current_time_p);
	std::strftime(clock, 9, "%H:%M:%S", current_time_p);

	std::cout << "Date: " << date << ", Time: " << clock << "." << std::flush;
}

void	Account::displayAccountsInfos(void) {
	std::cout << "AccInfo :: " << std::flush;
	_displayTimestamp();
	std::cout << " total accounts : " <<  getNbAccounts() << ", "
			<< "total amount : " << getTotalAmount() << "$, "
			<< "deposit : " << getNbDeposits() << " times, "
			<< "withdrawal : " << getNbWithdrawals() << " times." << std::endl;
}

void	Account::displayStatus(void) const {
	std::cout << "AccStatus :: " << std::flush;
	_displayTimestamp();
	std::cout << " account index : " << _accountIndex << ", "
			<< "amount left : " << checkAmount() << "$, "
			<< "deposit : " << _nbDeposits << " times, "
			<< "withdrawal : " << _nbWithdrawals << " times." << std::endl;
}

void	Account::makeDeposit(int deposit) {
	std::cout  << "Deposit :: " << std::flush;
	_displayTimestamp();
	std::cout << " account index : " << getNbAccounts()
			<< ", amount : " << checkAmount()
			<< "$, deposit : " << deposit << std::flush;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ", current amount : " << checkAmount()
			<< "$, did deposit " << _nbDeposits << " times." << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	std::cout  << "Withdrawal :: " << std::flush;
	_displayTimestamp();
	std::cout << " account index : " << getNbAccounts()
			<< ", amount : " << checkAmount()
			<< "$, withdrawal : " << withdrawal << std::flush;
	if (withdrawal > _amount) {
		std::cout << "$, Hello broke boy. You don't have enough money!" << std::endl;
		return (false);
	} else if (withdrawal > _totalAmount) {
		std::cout << "$, Sorry, We don't have cash for you right now." << std::endl;
		return (false);
	} else {
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "$, current amount : " << checkAmount()
				<< "$, did withdrawal " << _nbDeposits << " times." << std::endl;
		return (true);
	}
}
