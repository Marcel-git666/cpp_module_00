#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {

    _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";created\n";
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";closed\n";
}

void Account::makeDeposit(int deposit) {
    int pAmount = this->_amount;

    _displayTimestamp();

    this->_amount += deposit;
    this->_nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << " index:" << _accountIndex << ":p_amount:" << pAmount
              << ";deposit:" << deposit << ";amount:" << this->_amount
              << ";deposits:" << _nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ":p_amount:" << _amount
              << ";withdrawal:";
    if (withdrawal <= _amount) {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << ";amount:" << this->_amount
                  << ";nb_withdrawals:" << this->_nbWithdrawals << '\n';
        return true;
    } else {
        std::cout << "refused\n";
        return false;
    }
}

int Account::checkAmount(void) const { return this->_amount; }

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << '\n';
}

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals() << '\n';
}

void Account::_displayTimestamp(void) {
    char buffer[20];
    time_t now = time(0);
    tm *ltm = localtime(&now);

    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ltm);
    std::cout << buffer;
}

Account::Account(void) {}
