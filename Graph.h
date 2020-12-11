#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

#include "Airport.h"
#include "Route.h"

using std::string;
using std::vector;

class Graph {
   private:
    // Probably need to change these
    // Thinking that since we won't have to remove any routes or airports,
    // simple vector implementation might be fine Maps an airport to its
    // departing routes -- (should it map to just the airports?)
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>
        airports_;
    // Edge List -- If we will be checking if 2 airports are connected directly
    // then adjacency matrix better
    std::vector<Route> routes_;

   public:
    Graph(string airport_file, string route_file, string start_airport_ID);

    // For testing purposes
    Graph(std::vector<string> input);

    const Airport& get_airport_by_ID(std::string ID);
    std::vector<Route>& get_adjacent_routes_by_ID(std::string ID);
    void parse_airport_data(string airport_file, string start_airport_ID);
    void parse_routes_data(string route_file);

    int get_dist(Airport source, Airport destination);

    // TESTING
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>&
    get_airports();
    std::vector<Route>& get_routes();

    // Create getter for this
    Airport start_airport;
};