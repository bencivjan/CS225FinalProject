#include "Dijkstra.h"
#include "../BFS/BFS.h"
#include "../Airport.h"
#include "../Graph.h"

Dijkstra::Dijkstra(const Graph& original, const Airport& source) : full_graph(original) {
    //Need something for setting the original
    
    BFS bfs;
    bfs.traversal(original, source);
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


void Dijkstra::algorithm() {
    size_t num_nodes = connected_nodes.size();
    size_t i = 0;
    for(i = 0; i < num_nodes; i++){
        std::map<int, std::string>::iterator top = data.begin();
        const std::vector<Route>& curr_adjacent = full_graph.get_adjacent_routes_by_ID((*top).second);
        for(Route r : curr_adjacent){
            std::string curr_ID = r.get_destination().get_OpenFlightID();
            std::map<int, std::string>::iterator find = data.begin();
            // This if will be slow potentially
            while((*find).second != curr_ID){
                find++;
            }
            
        }
    }

}

