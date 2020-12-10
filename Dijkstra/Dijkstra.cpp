#include "Dijkstra.h"
#include "../BFS/BFS.h"
#include "../Airport.h"
#include "../Graph.h"

Dijkstra::Dijkstra(Graph original, const Airport& source) {
    //Need something for setting the original
    
    BFS bfs;
    connected_nodes = bfs.visited_airport_ids;
    
    for (size_t i = 0; i < connected_nodes.size(); i++) {
        if (source.get_OpenFlightID() == connected_nodes[i]) {
            data.insert(std::pair<int, std::string>(0, connected_nodes[i]));
        }
        else {
            data.insert(std::pair<int, std::string>(INT64_MAX, connected_nodes[i])); 
        }
        predecessor.insert(std::pair<std::string, std::string>("", ""));
    }    
}


std::unordered_map<std::string, int> Dijkstra::algorithm() {
    
}

