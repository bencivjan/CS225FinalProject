#pragma once

#include <unordered_map>
#include <vector>

#include "../Airport.h"
#include "../Graph.h"

using std::vector;

class Astar {
   public:
    vector<Airport> astarPath(Graph& graph, const Airport& start,
                              const Airport& end);

    int count_open;
    int count_closed;

   private:
    Airport runAstar(Graph& graph, const Airport& start, const Airport& end);

    // Helper function to get f cost
    int fcost(const Airport& a);

    // Helper function to get minimum f cost value in vector
    int min_fcost(const vector<Airport>& v);

    // Helper function to determine if airport exists in a vector
    bool exists(const vector<Airport>& v, const Airport& check);

    // Set of open nodes
    vector<Airport> open;
    // Set of closed nodes
    vector<Airport> closed;

    // Map to store h heuristics
    std::unordered_map<std::string, int> h;
    // Map to store g heuristics
    std::unordered_map<std::string, int> g;
    // Map to store f heuristics
    std::unordered_map<std::string, int> f;
    // Map to store parents
    std::unordered_map<std::string, Airport> parent;
};