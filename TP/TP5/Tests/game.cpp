#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;


unsigned int Game::numberOfWords(string phrase)
{
    if ( phrase.length() == 0 ) return 0;

    unsigned n=1;
    size_t pos = phrase.find(' ');
    while (pos != string::npos) {
        phrase = phrase.substr(pos+1);
        pos = phrase.find(' ');
        n++;
    }
    return n;
}

// TODO
Game::Game()
{
}

// TODO
Game::Game(list<Kid>& l2)
{
    kids = l2;
}

// TODO
void Game::addKid(const Kid &k1)
{
    kids.push_back(k1);
}

// TODO
list<Kid> Game::getKids() const
{
    return kids;
}

// TODO
string Game::write() const
{
    stringstream ss;
    auto it1 = kids.begin(), it2 = kids.end();

    while(it1 != it2){
        ss << (*it1).write() << endl;
        it1++;
    }

    return ss.str();
}

// TODO
Kid& Game::loseGame(string phrase)
{
    while (kids.size() != 1){
        auto it1 = kids.begin(), it2 = kids.end();
        std::string temp;
        stringstream ss(phrase);
        while(ss >> temp){
            it1++;
            if (it1 == it2)
                it1 = kids.begin();
        }
        kids.erase( it1 != kids.begin() ? --it1 : --it2 );
    }

    Kid *k1 = new Kid();
    *k1 = kids.front();
    return *k1;
}

// TODO
list<Kid>& Game::reverse()
{
    list<Kid> * newKids = new list<Kid>;
    *newKids = kids;
    (*newKids).reverse();
    return *newKids;
}

// TODO
list<Kid> Game::removeOlder(unsigned id)
{

    list<Kid> res = kids;

    res.erase(std::remove_if(res.begin(), res.end(), [id](Kid kid){ return kid.getAge() > id; }), kids.end());

    return res;
}

// TODO
void Game::setKids(const list<Kid>& l1)
{
    kids = l1;
}

// TODO
bool Game::operator==(Game& g2)
{
	return true;
}

// TODO
list<Kid> Game::shuffle() const
{
    list<Kid> res;
    return res;
}
