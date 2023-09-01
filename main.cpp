#include <iostream>
#include <string>
#include <utility>

#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main(int argc, char** argv) {
  if(argc == 3){
    if((string)argv[2] == "depth" || (string)argv[2] == "breadth"){
      if((string)argv[2] == "depth"){
        try{
          Maze* maze = loadMap((string)argv[1]);
          List<Position*>* solved = maze->solveDepthFirst();
          cout << renderAnswer(maze, solved) << endl;
          if(solved == NULL){
            cout << "No solution" << endl;
          }
          delete maze;
          delete solved;
        }
        catch(runtime_error e){ 
          cout << "There was an error. Here's why:" << endl;
          cout << e.what() << endl;
        }
      }
      else{
        try{
          Maze* maze = loadMap((string)argv[1]);
          List<Position*>* solved = maze->solveBreadthFirst();
          cout << renderAnswer(maze, solved) << endl;
          if(solved == NULL){
            cout << "No solution" << endl;
          }
          delete maze;
          delete solved;
        }
        catch(runtime_error e){
          cout << "There was an error. Here's why:" << endl;
          cout << e.what() << endl;
        }

      }
    }
    else{
      cout << "Invalid search type" << endl;
      cout << "Search types: breadth/depth" << endl;
    }
  }
  else{
    cout << "Invalid number of command-line arguments" << endl;
    cout << "usage: ./maze filename depth/breadth" << endl;
  }

  return 0;
}
