/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"

unsigned int BankOfficer::lastId = 0;

BankOfficer::BankOfficer(): id(0) {}

void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}

bool operator>(const BankOfficer &lhs, const BankOfficer &rhs) {
    return lhs.myAccounts.size() > rhs.myAccounts.size()
        || (lhs.myAccounts.size() == rhs.myAccounts.size() && lhs.name > rhs.name);
}

BankOfficer::BankOfficer(string nm) : name(nm) {
    id = ++lastId;
}

NoBankOfficerException::NoBankOfficerException(string name) : name(name){}

const char *NoBankOfficerException::what() const noexcept {
    return "No bank officer";
}

string NoBankOfficerException::getName() const {
    return name;
}
