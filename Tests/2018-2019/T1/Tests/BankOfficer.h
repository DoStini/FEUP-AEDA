/*
 * BankOfficer.h
 */

#ifndef SRC_BANKOFFICER_H_
#define SRC_BANKOFFICER_H_

#include "Account.h"
#include <string>
#include <vector>

class NoBankOfficerException : exception{
public:
    NoBankOfficerException(string name);
    string getName() const;
    const char * what() const noexcept override;
private:
    string name;
};


class BankOfficer {
	unsigned int id;
	string name;
	vector<Account *> myAccounts;
public:
	BankOfficer();
	void setName(string nm);
	void addAccount(Account *a);
	void addAccount(vector<Account *> accounts);
	string getName() const;
	vector<Account *> getAccounts() const;
	unsigned int getID() const;

	static unsigned int lastId;

    friend bool operator>(const BankOfficer &lhs, const BankOfficer &rhs);

	explicit BankOfficer(string nm);
	vector<Account *> removeBankOfficer(string name);
};

#endif /* SRC_BANKOFFICER_H_ */
