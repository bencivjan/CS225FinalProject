
#include "../Graph.h"
#include "../BFS/BFS.h"
class Dijkstra{
    private:
    // Connected nodes
    std::vector<std::string> connected_nodes;

    //maps a airport to its predicessor
    std::unordered_map<std::string, std::string> predecessor;

    //maps a path weight to a certatin airport
    std::multimap<double, std::string> data;

    std::unordered_map<std::string, double> rev_data;

    Graph& full_graph;

    public:
    std::unordered_map<std::string, double> SSSP;

    Dijkstra(Graph& original, const Airport& source);
    void algorithm();

    
};