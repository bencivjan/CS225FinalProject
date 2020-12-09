#pragma once

#include <unordered_map>
#include <vector>

#include "../Airport.h"
#include "../Graph.h"

using std::vector;

class Astar {
    void runAstar(Graph g, Airport start, Airport end);
};