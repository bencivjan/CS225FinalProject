#pragma once
#include "../Graph.h"
class Dijkstra{
    private:
    // Connected nodes
    std::vector<Airport> connected_component;
    public:
    Graph Path(const Graph& component);
    
};