//
// Created by andre on 10/25/2020.
//

#include "PositionDoesNotExiste.h"

PositionDoesNotExist::PositionDoesNotExist(unsigned int pos) : pos(pos) {}

unsigned PositionDoesNotExist::getPosition() {
    return pos;
}