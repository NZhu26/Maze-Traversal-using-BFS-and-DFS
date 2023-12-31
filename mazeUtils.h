#pragma once
#include <string>

#include "adts/list.h"
#include "maze.h"

using std::string;

/**
 * Reads a map from the specified file.
 * @param filename The name of the map file.
 * @return A pointer to the Maze object containing that map.  Deleting this
 *         object is the caller's responsibility.
 * @throws runtime_error If an error occurs while reading the file.
 */
Maze* loadMap(string filename);

/**
 * Transforms a solution into a string.
 * @param maze The Maze to use.
 * @param solution A list of the Position objects in the path.
 * @return The string representing the solution.
 */
string renderAnswer(Maze* maze, List<Position*>* solution);
