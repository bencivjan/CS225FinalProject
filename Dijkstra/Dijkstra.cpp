#include "Dijkstra.h"

#include "../Airport.h"
#include "../BFS/BFS.h"
#include "../Graph.h"

Dijkstra::Dijkstra(Graph& original, const Airport& source)
    : full_graph(original) {
    BFS bfs;
    bfs.traversal(original, source);
    connected_nodes = bfs.visited_airport_ids;
    int length = connected_nodes.size();
    int i = 0;
    for (i = 0; i < length; i++) {
        if (source.get_OpenFlightID() == connected_nodes[i]) {
            data.insert(std::pair<double, std::string>(0, connected_nodes[i]));
            rev_data.insert(
                std::pair<std::string, double>(connected_nodes[i], 0));
        } else {
            data.insert(
                std::pair<double, std::string>(DBL_MAX, connected_nodes[i]));
            rev_data.insert(
                std::pair<std::string, double>(connected_nodes[i], DBL_MAX));
        }

        predecessor.insert(
            std::pair<std::string, std::string>(connected_nodes[i], ""));
    }
}

std::unordered_map<std::string, double> Dijkstra::algorithm() {
    int num_nodes = (int)data.size();
    int i = 0;
    for (i = 0; i < num_nodes; i++) {
        std::multimap<double, std::string>::iterator top = data.begin();
        std::vector<Route>& curr_adjacent =
            full_graph.get_adjacent_routes_by_ID((*top).second);
        int num_adj = (int)curr_adjacent.size();

        int j = 0;
        for (j = 0; j < num_adj; j++) {
            if (SSSP.count(
                    curr_adjacent[j].get_destination().get_OpenFlightID())) {
                continue;
            }

            // Good until here
            std::string curr_ID =
                curr_adjacent[j].get_destination().get_OpenFlightID();
            if ((*top).first + curr_adjacent[j].get_weight() <
                rev_data[curr_ID]) {
                rev_data[curr_ID] =
                    (*top).first + curr_adjacent[j].get_weight();
                std::multimap<double, std::string>::iterator search =
                    data.begin();
                while ((*search).second != curr_ID && search != data.end()) {
                    if ((*search).second == curr_ID) {
                        break;
                    }

                    std::pair<std::multimap<double, std::string>::iterator,
                              std::multimap<double, std::string>::iterator>
                        range = data.equal_range((*search).first);
                    std::multimap<double, std::string>::iterator temp =
                        range.first;
                    if (!data.count((*search).first)) {
                        if (data.count((*search).first)) {
                            data.erase(search);
                            data.insert(std::pair<double, std::string>(
                                (*top).first + curr_adjacent[j].get_weight() +
                                    j,
                                curr_ID));
                        }
                        continue;
                    }
                    while (temp != range.second) {
                        if ((*temp).second == curr_ID) {
                            (*search).second = curr_ID;
                            break;
                        }
                        temp++;
                    }
                    if (((*search).second == curr_ID)) {
                        break;
                    }
                    search++;
                }
                if (search == data.end()) {
                    continue;
                }
                data.erase(search);
                data.insert(std::pair<double, std::string>(
                    (*top).first + curr_adjacent[j].get_weight(), curr_ID));
                predecessor[curr_ID] = (*top).second;
            }
        }
        SSSP.insert(std::pair<std::string, int>((*top).second, (*top).first));
        data.erase(top);
    }
    return SSSP;
}
