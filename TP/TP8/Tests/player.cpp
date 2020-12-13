#include "player.h"

void Player::addBet(const Bet& b)
{
    bets.insert(b);
}

unsigned Player::betsInNumber(unsigned num) const
{
	return std::count_if(bets.begin(),
                    bets.end(),
                    [num](const Bet & bet){
	                    return bet.contains(num);
	                });
}

tabHBet Player::drawnBets(const tabHInt& draw) const
{
	tabHBet res;

    for (const auto& bet : bets){
        if(bet.countRights(draw)>3) res.insert(bet);
    }

	return res;
}
