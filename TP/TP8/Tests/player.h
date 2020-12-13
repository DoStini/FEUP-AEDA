#ifndef PLAYER_H_
#define PLAYER_H_

#include "bet.h"
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

struct betHash
{
	int operator() (const Bet& b) const
	{
	    int sum = 0;
        for (unsigned int it : b.getNumbers()) {
            sum = sum*37 + (int)it;
        }
        std::cout << "Sum: " << sum << std::endl;
        return sum;
	}
	
	bool operator() (const Bet& b1, const Bet& b2) const
	{
		return b1.getNumbers() == b2.getNumbers();
	}
};


typedef unordered_set<Bet, betHash, betHash> tabHBet;

class Player
{
	tabHBet bets;
	string name;
public:
	Player(string nm="anonymous") { name=nm; }
	void addBet(const Bet & ap);
	unsigned betsInNumber(unsigned num) const;
	tabHBet drawnBets(const tabHInt& draw) const;
	unsigned getNumBets() const { return bets.size(); }
};

#endif 
