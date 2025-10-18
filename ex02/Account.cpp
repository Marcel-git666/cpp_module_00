#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += _amount;
    // Zde přijde váš kód pro inicializaci objektu...
    // Budete muset pracovat se statickými i nestatickými proměnnými.
}

// Implementace destruktoru
Account::~Account(void) {
    // Zde přijde váš kód pro "úklid" při zničení objektu...
    // Log soubor napoví, co se má vypsat.
}

void Account::makeDeposit(int deposit) {
    _amount += deposit;
    _totalNbDeposits++;
    // Zde přijde váš kód pro zpracování vkladu...
}

bool Account::makeWithdrawal(int withdrawal) {
    _amount -= withdrawal;
    _totalNbWithdrawals++;
    //
    return false;
}

int Account::checkAmount(void) const {
    //
    return 0;
}

void Account::displayStatus(void) const {
    // Zde přijde váš kód pro zobrazení stavu jednoho účtu...
}

int Account::getNbAccounts(void) {
    //
    return 0;
}

int Account::getTotalAmount(void) {
    //
    return 0;
}

int Account::getNbDeposits(void) {
    //
    return 0;
}
int Account::getNbWithdrawals(void) {
    //
    return 0;
}

void Account::displayAccountsInfos(void) {
    // Zde přijde váš kód pro zobrazení souhrnných informací...
}
