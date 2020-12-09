#pragma once

#include <queue>
#include <unordered_map>

#include "../Graph.h"
#include "../cs225/PNG.h"

using std::queue;

class BFS {
   public:
    void traversal(Graph g, Airport start);

    int count;
    Airport start_airport;
    Airport end_airport;
    std::vector<std::string> visited_airport_ids;
};