#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Airport.h"
#include "Route.h"

class Graph {
   private:
   public:
    Graph();

    const Airport& get_airport_by_ID(std::string ID);
    const std::vector<Route>& get_adjacent_routues_by_ID(std::string ID);
    void parse_airport_data();
    void parse_routes_data();

    // TESTING
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>&
    get_airports();
    std::vector<Route>& get_routes();

    // MAKE THESE PRIVATE AT THE END, PUBLIC FOR DEBUGGING PURPOSES

    // Probably need to change these
    // Thinking that since we won't have to remove any routes or airports,
    // simple vector implementation might be fine Maps an airport to its
    // departing routes -- (should it map to just the airports?)
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>
        airports_;
    // Edge List -- If we will be checking if 2 airports are connected directly
    // then adjacency matrix better
    std::vector<Route> routes_;
};