#include "Dijkstra.h"
#include "../BFS/BFS.h"
#include "../Airport.h"
#include "../Graph.h"

Dijkstra::Dijkstra(Graph& original, const Airport& source) : full_graph(original) {
    //Need something for setting the original
    BFS bfs;
    bfs.traversal(original, source);
    connected_nodes = bfs.visited_airport_ids;
    int length = connected_nodes.size();
    int i = 0;
    for (i = 0; i < length; i++) {
        if (source.get_OpenFlightID() == connected_nodes[i]) {
            std::cout << "SourceID = " << connected_nodes[i] << "\n";
            data.insert(std::pair<double, std::string>(0, connected_nodes[i]));
            rev_data.insert(std::pair<std::string, double>(connected_nodes[i],0));
        }
        else {
            data.insert(std::pair<double, std::string>(INT32_MAX, connected_nodes[i])); 
            rev_data.insert(std::pair<std::string, double>(connected_nodes[i],INT32_MAX));
        }

        predecessor.insert(std::pair<std::string, std::string>(connected_nodes[i], ""));
    }
}


void Dijkstra::algorithm() {    
    int num_nodes = (int)data.size();
    int i = 0;
    for(i = 0; i < num_nodes; i++){
        std::cout << "Total Nodes = " << num_nodes << "\n";
        std::map<double, std::string>::iterator top = data.begin();
        std::vector<Route>& curr_adjacent = full_graph.get_adjacent_routes_by_ID((*top).second);
        int num_adj = (int)curr_adjacent.size();
        std::cout << "Num Currently Adj = " << num_adj << "\n";
        std::cout << "Lowest weight = " << (*top).first << " Lowest ID = " << (*top).second << "\n";

        int j = 0;
        for(j = 0; j < num_adj; j++){
            if(SSSP.count(curr_adjacent[j].get_destination().get_OpenFlightID())){
                continue;
            }
            
            // Good until here
            std::string curr_ID = curr_adjacent[j].get_destination().get_OpenFlightID();
            //std::cout << "Curr Weight = " << curr_adjacent[i].get_weight() << "\n";
            std::string found = rev_data.count(curr_ID) ? "Yes":"No";
            std::cout << "Found? " << found << "\n";
            std::cout << "Adj Airport " << curr_ID << " Current Path " << rev_data[curr_ID] << "\n";
            if((*top).first + curr_adjacent[j].get_weight() < rev_data[curr_ID]){
                rev_data[curr_ID] = (*top).first + curr_adjacent[j].get_weight();
                std::map<double, std::string>::iterator search = data.begin(); //lower_bound((*top).first + curr_adjacent[j].get_weight());

                /**********************/
                // Bug in this part
                // Everything above should be good
                // All this is doing is getting each key value pair and checking if
                // the current airport ID mathces the one we are currently analyzing (stored in curr_ID variable)

                while((*search).second != curr_ID && search != data.end()){
                    std::cout << "It = " << (*search).second << " currID = " <<  curr_ID << "\n";
                    search++;
                    if((*search).second == curr_ID){
                        break;
                    }
                    // This equal_range function is supposed to return iterators to the start and end boundary
                    // of all pairs in the map that have the given key ( *search.first ) but it isn't working for some reason
                    // if can't get to work we can just use the regular map, find the largest possible lat-long distance
                    // on earth and make each key some number larger than that
                    std::pair<std::map<double, std::string>::iterator , std::map<double, std::string>::iterator> range = data.equal_range((*search).first);
                    std::map<double, std::string>::iterator temp = range.first;
                    while(temp != range.second){
                        if((*temp).second == curr_ID){
                            std::cout << "It = " << (*temp).second << " currID = " <<  curr_ID << "\n";
                            (*search).second = curr_ID;
                            break;
                        }
                        temp++;
                    }   
                }

                // Things after this point should be good but havent checked to be sure

                // Error check iterator
                if(search == data.end()){
                    std::cout << "ERROR FINDING PORT\n";
                    return;
                }
                double old = (*search).first;
                data.erase(old);
                data.insert(std::pair<double, std::string>((*top).first + curr_adjacent[j].get_weight(), curr_ID));
                predecessor[curr_ID] = (*top).second;
            }
        }
        SSSP.insert(std::pair<std::string, int>((*top).second, (*top).first));
        data.erase(top);
    }
    return;
}

