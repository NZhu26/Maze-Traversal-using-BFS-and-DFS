#include <stdexcept>

/* ADTs */
#include "adts/list.h"
#include "adts/orderedCollection.h"
#include "adts/queue.h"
#include "adts/stack.h"

/* Implementations of above ADTs */
#include "adts/stlList.h"
#include "linkedQueue.h"
#include "linkedStack.h"

#include "maze.h"

using namespace std;

Maze::Maze(int width, int height) {
  this->width = width;
  this->height = height;
  this->positions = new Position**[width];
  for(int i=0; i<width; i++){
    this->positions[i] = new Position*[height];
    for(int j=0; j<height; j++){
      this->positions[i][j] = new Position(i, j);
    }
  }
}

Maze::~Maze() {
  for(int i=0; i<this->width; i++){
    for(int j=0; j<this->height; j++){
      delete this->positions[i][j];
    }
    delete[] this->positions[i];
  }
  delete[] this->positions;
}

int Maze::getWidth() {
  return this->width;
}

int Maze::getHeight() {
  return this->height;
}

bool Maze::isWall(int x, int y) {
  if(this->positions[x][y]->isWall()){
    return true;
  }
  else{
    return false;
  }
}

void Maze::setWall(int x, int y) {
  this->positions[x][y]->setWall();
}

List<Position*>* Maze::getNeighbors(Position* position) {
  STLList<Position*>* list = new STLList<Position*>();
  int x = position->getX();
  int y = position->getY();

  if(x-1 >= 0 && !this->positions[x-1][y]->isWall()){
    list->insertLast(this->positions[x-1][y]);
  }
  if(x+1 < this->width && !this->positions[x+1][y]->isWall()){
    list->insertLast(this->positions[x+1][y]);
  }
  if(y-1 >= 0 && !this->positions[x][y-1]->isWall()){
    list->insertLast(this->positions[x][y-1]);
  }
  if(y+1 < this->height && !this->positions[x][y+1]->isWall()){
    list->insertLast(this->positions[x][y+1]);
  }

  return list;
}

List<Position*>* Maze::solveBreadthFirst() {
  LinkedQueue<Position *>* queue = new LinkedQueue<Position *>();
  return solve(queue);
}

List<Position*>* Maze::solveDepthFirst() {
  LinkedStack<Position *>* stack = new LinkedStack<Position *>();
  return solve(stack);
}

List<Position*>* Maze::solve(OrderedCollection<Position*>* exploration) {
  exploration->insert(this->positions[0][0]);
  while(!exploration->isEmpty()){
    Position* current = exploration->remove();
    if(current->isVisited()){
      continue;
    }
    current->setVisited();
    if(current->getX() == getWidth()-1 && current->getY() == getHeight()-1){
      break;
    }
    List<Position*>* neighbors = getNeighbors(current);
    for(int i=0; i<neighbors->getSize(); i++){
      if(!neighbors->get(i)->isVisited()){
        if(neighbors->get(i)->getPrevious() == NULL){
          neighbors->get(i)->setPrevious(current);
        }
        exploration->insert(neighbors->get(i));
      }
    }
    delete neighbors;
  }
  delete exploration;
  if(this->positions[getWidth()-1][getHeight()-1]->isVisited()){
    STLList<Position*>* solved = new STLList<Position*>();
    Position* p1 = this->positions[getWidth()-1][getHeight()-1];
    while(p1 != NULL){
      solved->insertFirst(p1);
      p1 = p1->getPrevious();
    }
    return solved;
  }
  else{
    return NULL;
  }
}
