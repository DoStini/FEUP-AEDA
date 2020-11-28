#include "game.h"
#include <sstream>


//TODO
ostream &operator << (ostream &os, Circle &c1)
{
	return os;
}

BinaryTree<Circle> Game::createTree(int h, int p, vector<int> &points, vector<bool> &states) {
    if(h == 0) return BinaryTree<Circle>(Circle(points[p], points[p]));
    return BinaryTree<Circle>(
            Circle(points[p], states[p]),
            createTree(h-1, 2*p+1, points, states),
            createTree(h-1, 2*p+2, points, states));
}

Game::Game(int h, vector<int> &points, vector<bool> &states)
{
    game = BinaryTree<Circle>(createTree(h, 0, points, states));
    //game = BinaryTree<Circle>(root);
}


//TODO
string Game::writeGame()
{
    std::stringstream ss;
    BTItrLevel<Circle> it(game);
    while (!it.isAtEnd()){
        ss << it.retrieve().getPoints() << "-" <<
                (it.retrieve().getState() ? "true" : "false") << "-" <<
                it.retrieve().getNVisits() << '\n';
        it.advance();
    }
	return ss.str();
}


//TODO
int Game::move()
{
    BTItrLevel<Circle> it(game);
    BTItrLevel<Circle> bef(game);

    int pos = 0;
    bool end = false;
    while (!end){
        int nextPos = 2*pos + 1 + (int)it.retrieve().getState();
        it.retrieve().changeState();
        it.retrieve().addVisit();
        bef = it;
        while (pos != nextPos){
            pos ++;
            if(it.isAtEnd()) end = true;
            else it.advance();
        }
    }

	return bef.retrieve().getPoints();
}


//TODO
int Game::mostVisited()
{
    BTItrLevel<Circle> it(game); it.advance();
    int max = -1;
    while (!it.isAtEnd()){
        int pt = it.retrieve().getNVisits();
        if( pt > max ) max = pt;
        it.advance();
    }
	return max;
}

