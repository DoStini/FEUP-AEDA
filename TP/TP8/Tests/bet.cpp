#include "bet.h"
#include <iostream>
#include <sstream>
using namespace std;


bool Bet::contains(unsigned num) const
{
	return numbers.find(num) != numbers.end();
}

void Bet::generateBet(const vector<unsigned>& values, unsigned n)
{
    int h = 0;
    for (int i = 0; i < n;) {
        if(numbers.find(values[h])==numbers.end()){
            numbers.insert(values[h]);
            i++;
        }
        h++;
    }
}

unsigned Bet::countRights(const tabHInt& draw) const
{
	auto it = draw.begin();
	unsigned count = 0;
	for (;it != draw.end(); it++) if(numbers.find(*it) != draw.end()) count++;

	return count;
}
