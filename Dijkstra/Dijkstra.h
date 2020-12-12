
#include <float.h>

#include "../BFS/BFS.h"
#include "../Graph.h"
class Dijkstra {
   private:
    std::vector<std::string> connected_nodes;

    std::unordered_map<std::string, std::string> predecessor;

    std::multimap<double, std::string> data;

    std::unordered_map<std::string, double> rev_data;

    Graph& full_graph;

   public:
    std::unordered_map<std::string, double> SSSP;

    Dijkstra(Graph& original, const Airport& source);
    std::unordered_map<std::string, double> algorithm();
};