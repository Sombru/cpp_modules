#include ".includes.hpp"

// get timestamp
// get index:X;
// get amount:Y;
// "created"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex 
				<< ";amount:" 
				<< initial_deposit 
				<< ":created\n";
}

Account::~Account()
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex 
				<< ";amount:" 
				<< checkAmount() 
				<< ":closed\n";
}
void Account::_displayTimestamp()
{
    std::time_t now = std::time(NULL);
    std::tm *local_time = std::localtime(&now);

    char buffer[20]; // Buffer to store the formatted timestamp
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", local_time);

    std::cout << '[' << buffer << "] ";
}

// getters
int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

int Account::checkAmount() const
{
	return this->_amount;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout	<< "accounts:"
				<< _nbAccounts 
				<< ";total:" 
				<< getTotalAmount() 
				<< ";deposits:"
				<< getNbDeposits()
				<< ";withdrawals:"
				<< getNbWithdrawals()
				<< '\n';
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex
				<< ";amount:"
				<< checkAmount()
				<< ";deposits:"
				<< this->_nbDeposits
				<< ";withdrawals:"
				<< this->_nbWithdrawals
				<< '\n';
}

// setters
void Account::makeDeposit(int deposit)
{
	_totalNbDeposits++;
	_totalAmount += deposit;
	this->_nbDeposits++;
	this->_amount += deposit;
	
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex 
				<< ";p_amount:" 
				<< this->_amount - deposit
				<< ";deposit:"
				<< deposit
				<< ";amount:"
				<< this->_amount
				<< ";nb_deposits:"
				<< this->_nbDeposits
				<< '\n';
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > this->_amount)
	{
		_displayTimestamp();
		std::cout	<< "index:"
					<< _accountIndex
					<< ";p_amount:"
					<< this->_amount
					<< ";withdrawal:refused"
					<< '\n';
		return (false);
	}

	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	_displayTimestamp();
	std::cout	<< "index:"
				<< _accountIndex 
				<< ";p_amount:" 
				<< this->_amount + withdrawal
				<< ";withdrawal:"
				<< withdrawal
				<< ";amount:"
				<< this->_amount
				<< ";nb_withdrawals:"
				<< this->_nbWithdrawals
				<< '\n';
	return (true);
}