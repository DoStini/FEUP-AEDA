/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

double Bank::getWithdraw(string cod1) const{
    double out;
    for(Account * ptr : accounts){
        if(ptr->getCodH() == cod1)
            out += ptr->getWithdraw();
    }
    return out;
}


vector<Account *> Bank::removeBankOfficer(string name){
    auto it = std::find_if(bankOfficers.begin(),
                 bankOfficers.end(),
                 [name](const BankOfficer & off){
                    return off.getName() == name;
                 });

	vector<Account *> res;
	if(it != bankOfficers.end()) {
	    res = it->getAccounts();
        bankOfficers.erase(it);
    }
	return res;
}


// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    BankOfficer * ref;
    try {
        ref = &findBankOfficer(name);
    } catch (NoBankOfficerException e) {
        throw e;
    }
    ref->addAccount(ac);
    return *ref;
}


void Bank::sortAccounts() {
    sort(accounts.begin(),
         accounts.end(),
         [](const Account * ptr1, const Account * ptr2){
            return ptr2->getBalance() > ptr1->getBalance() ||
                    ( ptr1->getBalance() == ptr2->getBalance() && ptr2->getCodIBAN() > ptr1->getCodIBAN() );
    });
}

BankOfficer & Bank::findBankOfficer(string name) {
    auto it = std::find_if(bankOfficers.begin(),
                           bankOfficers.end(),
                           [name](const BankOfficer & off){
                               return off.getName() == name;
                           });

    if(it == bankOfficers.end()) throw NoBankOfficerException(name);
    return *it;
}

