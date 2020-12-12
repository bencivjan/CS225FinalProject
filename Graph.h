#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "Airport.h"
#include "Route.h"

using std::string;
using std::vector;

class Graph {
   private:
    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>
        airports_;

    std::vector<Route> routes_;

   public:
    Graph(string airport_file, string route_file, string start_airport_ID);

    Graph(std::vector<string> input);

    const Airport& get_airport_by_ID(std::string ID);
    std::vector<Route>& get_adjacent_routes_by_ID(std::string ID);
    void parse_airport_data(string airport_file, string start_airport_ID);
    void parse_routes_data(string route_file);

    int get_dist(Airport source, Airport destination);

    std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>&
    get_airports();
    std::vector<Route>& get_routes();

    Airport start_airport;
};