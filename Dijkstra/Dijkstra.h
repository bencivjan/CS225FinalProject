#pragma once
#include "../Graph.h"
class Dijkstra{
    private:
    // Connected nodes
    std::vector<Airport> connected_nodes;
    std::unordered_map<std::string, const Airport&> predecessor;
    Graph& full;

    public:
    Dijkstra(Graph& original, const Airport& source);

    std::vector<std::pair<const Airport&, double>> algorithm();
    
};