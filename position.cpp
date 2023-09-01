#include "position.h"
#include <stdexcept>

using namespace std;

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
    this->wall = false;
    this->visited = false;
    this->previous = nullptr;
}

int Position::getX() {
    return this->x;
}

int Position::getY() {
    return this->y;
}

void Position::setWall() {
    this->wall = true;
}

bool Position::isWall() {
    return this->wall;
}

bool Position::isVisited() {
    return this->visited;
}

void Position::setVisited() {
    this->visited = true;
}

void Position::clearVisited() {
    this->visited = false;
    this->previous = nullptr;
}

Position* Position::getPrevious() {
    return this->previous;
}

void Position::setPrevious(Position* pos) {
    this->previous = pos;
}
