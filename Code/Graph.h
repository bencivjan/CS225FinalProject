#pragma once
#include "Airport.h"
#include "Route.h"
#include "hash.cpp"
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>



class Graph{
    private:
    // Probably need to change these
    // Thinking that since we won't have to remove any routes or airports, simple vector implementation might be fine
    // Maps an airport to its departing routes -- (should it map to just the airports?)
    std::unordered_map<Airport, std::vector<Route>> airports_;
    // Edge List -- If we will be checking if 2 airports are connected directly then adjacency matrix better
    std::vector<Route> routes_;

    public:
    Graph();

    bool direct_route_exists(Airport source, Airport destination);
    std::vector<Airport> BFS(Airport start);
    std::vector<Route> shortest_path(Airport start, Airport destination);

    // Random idea, spanning tree of all airports in contact with a certain source, could be useful for force graph
    std::vector<Airport> find_connected(Airport start);
    

    // TESTING
    std::unordered_map<Airport, std::vector<Route>>& data();
};